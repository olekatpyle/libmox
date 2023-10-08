#include "../../include/i_array.h"
#include "../../include/sort.h"

void merge_parts(i_array *ia, uint32_t left, uint32_t mid, uint32_t right,
		 int32_t helper[])
{
	for (uint32_t i = left; i <= right; i++) {
		helper[i] = ia_get(ia, i);
	}

	uint32_t i = left;
	uint32_t j = mid + 1;
	uint32_t k = left;

	while (i <= mid && j <= right) {
		if (helper[i] <= helper[j]) {
			ia_set(ia, k, helper[i]);
			i++;
		} else {
			ia_set(ia, k, helper[j]);
			j++;
		}
		k++;
	}
	while (i <= mid) {
		ia_set(ia, k, helper[i]);
		k++;
		i++;
	}
	while (j <= right) {
		ia_set(ia, k, helper[j]);
		k++;
		j++;
	}
}

void rec_merge(i_array *ia, uint32_t left, uint32_t right, int32_t helper[])
{
	if (right - left > 0) {
		uint32_t mid = (left + right) / 2;
		rec_merge(ia, left, mid, helper);
		rec_merge(ia, mid + 1, right, helper);
		merge_parts(ia, left, mid, right, helper);
	}
}

i_array *merge_sort(i_array *ia)
{
	int32_t helper[ia->size];
	rec_merge(ia, 0, ia->size - 1, helper);
	return ia;
}
