#include "../../include/hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
	char *key;
	void *object;
	struct entry *next;
} entry;

struct _hash_map {
	uint64_t size;
	hash_function *hash;
	cleanup_function *cleanup;
	entry **buckets;
};

uint64_t default_hash(const char *key, size_t length)
{
	printf("%s %p", key, &length);

	return 0;
}

static size_t hmap_idx(hash_map *hm, const char *key)
{
	size_t h = (hm->hash(key, strlen(key)) % hm->size);
	return h;
}

hash_map *hmap_create(uint64_t size, hash_function *hf, cleanup_function *cf)
{
	hash_map *hm = malloc(sizeof(*hm));

	// check if actually allocated memory
	if (hm == NULL) {
		return NULL;
	}

	hm->size = size;

	// check if custom hash function is provided
	if (hf == NULL) {
		hm->hash = &default_hash;
	} else {
		hm->hash = hf;
	}

	if (cf == NULL) {
		hm->cleanup = free;
	} else {
		hm->cleanup = cf;
	}

	// note that calloc zeros out the memory
	hm->buckets = calloc(sizeof(entry *), hm->size);
	// check again for allocation
	if (hm->buckets == NULL) {
		free(hm);
		return NULL;
	}
	return hm;
}

void hmap_destroy(hash_map *hm)
{
	for (uint64_t i = 0; i < hm->size; i++) {
		while (hm->buckets[i] != NULL) {
			entry *tmp = hm->buckets[i];
			hm->buckets[i] = hm->buckets[i]->next;
			free(tmp->key);
			// use passed in cleanup or default free
			hm->cleanup(tmp->object);
			free(tmp);
		}
	}
	free(hm->buckets);
	free(hm);
}

bool hmap_insert(hash_map *hm, const char *key, void *object)
{
	if (key == NULL || object == NULL) {
		return false;
	}

	uint64_t idx = hmap_idx(hm, key);
	printf("%ld", idx);

	entry *e = malloc(sizeof(*e));
	e->object = object;
	e->key = strdup(key);

	// allocated?
	if (e == NULL) {
		return false;
	}
	// in case of collision old head will be e->next, else e->next equals NULL since we used calloc to allocate memory for buckets
	e->next = hm->buckets[idx];
	// insert always as new head of bucket
	hm->buckets[idx] = e;

	return true;
}

void hmap_print(hash_map *hm)
{
	for (uint64_t i = 0; i < hm->size; i++) {
		uint32_t c = 1;
		if (hm->buckets[i]) {
			printf("%d", c);
			printf("[%lu - %p]", i, &hm->buckets[i]);
			while (hm->buckets[i + c++] != NULL) {
				printf("-[%lu - %p]", i + 1,
				       &hm->buckets[i + 1]);
			}
			printf("\n");
		} else {
			printf("< empty >");
		}
	}
}
