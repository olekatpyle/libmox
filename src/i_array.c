#include "../include/i_array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

i_array *ia_create(uint32_t size)
{
	i_array *ia = malloc(sizeof(i_array));
	// TODO  07/12/23 - 10:00: check pointer for NULL in case malloc
	// wasn't able to allocate memory
	ia->size = size;
	ia->num_entries = 0;
	ia->values = malloc(sizeof(int32_t) * size);

	// init the array with all zero
	for (uint32_t i = 0; i < ia->size; i++) {
		ia->values[i] = 0;
	}

	return ia;
}

void ia_destroy(i_array *ia)
{
	free(ia->values);
	free(ia);
}

bool ia_push(i_array *ia, int32_t value)
{
	if ((ia->num_entries) == (ia->size))
		return false;

	ia->values[ia->num_entries] = value;
	ia->num_entries++;

	return true;
}

bool ia_set(i_array *ia, uint32_t idx, int32_t value)
{
	// check idx in bounds of array
	if (idx > ia->size - 1)
		return false;

	ia->values[idx] = value;
	return true;
}

int ia_get(i_array *ia, uint32_t idx)
{
	if (idx > ia->size - 1)
		return -1;
	return ia->values[idx];
}

i_array *ia_copy(i_array *ia)
{
	i_array *ia_cpy = ia_create(ia->size);
	for (uint32_t i = 0; i < ia->size; i++) {
		int val = ia_get(ia, i);
		ia_push(ia_cpy, val);
	}
	return ia_cpy;
}

bool ia_equals(i_array *ia, i_array *ib)
{
	if ((ia->size != ib->size) || (ia->num_entries != ib->num_entries))
		return false;

	uint32_t c = 0;
	do {
		if (ia->values[c] != ib->values[c])
			return false;
		c++;
	} while (c < ia->size);
	return true;
}

void print_array(i_array *ia)
{
	printf("[");
	for (uint32_t i = 0; i < ia->num_entries - 1; i++) {
		printf("%d, ", ia->values[i]);
	}
	// last element
	printf("%d]\n", ia->values[ia->num_entries - 1]);
}
