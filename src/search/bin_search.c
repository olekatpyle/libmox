#include "../../include/bin_search.h"
#include "../util.h"
#include <stdio.h>

uint32_t bin_search_internal(int32_t *values, int32_t s, uint32_t lower_b,
			     uint32_t upper_b)
{
	if (upper_b < lower_b)
		return upper_b;

	uint32_t mid = lower_b + ((upper_b - lower_b) / 2);

	if (values[mid] > s)
		return bin_search_internal(values, s, lower_b, (mid - 1));
	else
		return bin_search_internal(values, s, (mid + 1), upper_b);
}

int32_t bin_search(i_array *ia, int32_t searchvalue)
{
	if (!is_sorted(ia))
		return NOT_FOUND;

	uint32_t result = bin_search_internal(ia->values, searchvalue, 0,
					      (ia->num_entries - 1));

	if (ia->values[result] != searchvalue) {
		return NOT_FOUND;
	}
	return result;
}
