#include "../../include/i_array.h"
#include "../../include/sort.h"

uint32_t partition(i_array *ia, int32_t left, int32_t right)
{
	// test different strategies
	int32_t pivot = ia_get(ia, right);

	int32_t i = left;
	int32_t j = right - 1;
	while (i < j) {
		while (ia->values[i] < pivot) {
			i++;
		}

		while (j > left && ia->values[j] >= pivot) {
			j--;
		}

		if (i < j) {
			swap(ia, i, j);
			i++;
			j--;
		}
	}

	if (i == j && ia->values[i] < pivot) {
		i++;
	}

	if (ia->values[i] != pivot) {
		swap(ia, i, right);
	}

	return i;
}

void rec_quick(i_array *ia, int32_t left, int32_t right)
{
	if (left >= right)
		return;

	uint32_t p_idx = partition(ia, left, right);
	rec_quick(ia, left, p_idx - 1);
	rec_quick(ia, p_idx + 1, right);
}

i_array *quick_sort(i_array *ia)
{
	rec_quick(ia, 0, ia->size - 1);
	return ia;
}
