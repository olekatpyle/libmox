#include "../../include/i_array.h"
#include "../../include/sort.h"
#include <stdbool.h>

i_array *bubble_sort(i_array *ia)
{
	bool swapped = false;
	do {
		swapped = false;
		for (uint32_t i = 0; i < ia->size - 1; i++) {
			if (ia->values[i] > ia->values[i + 1]) {
				swap(ia, i, i + 1);
				swapped = true;
			}
		}
	} while (swapped);

	return ia;
}

void swap(i_array *ia, uint32_t left_for_swap, uint32_t right_for_swap)
{
	int32_t tmp = ia_get(ia, left_for_swap);
	ia_set(ia, left_for_swap, ia_get(ia, right_for_swap));
	ia_set(ia, right_for_swap, tmp);
}
