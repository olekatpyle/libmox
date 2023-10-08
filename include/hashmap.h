#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

typedef struct _hash_map hash_map;
typedef uint64_t hash_function(const char *key, size_t length);
typedef void cleanup_function(void *);

hash_map *hmap_create(uint64_t size, hash_function *hf, cleanup_function *cf);
void hmap_destroy(hash_map *hm);
void hmap_print(hash_map *hm);
bool hmap_insert(hash_map *hm, const char *key, void *object);

#endif // !HASHT_H
