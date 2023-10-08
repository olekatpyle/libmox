#include "../../include/i_array.h"
#include "../../include/sort.h"

i_array *selection_sort(i_array *ia)
{
	for (uint32_t i = 0; i < ia->size - 1; i++) {
		uint32_t min_idx = i;
		for (uint32_t j = i + 1; j < ia->size; j++) {
			if (ia->values[j] < ia->values[min_idx])
				min_idx = j;
		}
		swap(ia, i, min_idx);
	}

	return ia;
}
