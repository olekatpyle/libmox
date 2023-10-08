#include "util.h"

bool is_sorted(i_array *ia)
{
	for (uint32_t i = 1; i < ia->size; i++) {
		if (ia->values[i - 1] > ia->values[i])
			return false;
	}
	return true;
}
