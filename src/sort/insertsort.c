#include "../../include/i_array.h"
#include "../../include/sort.h"

i_array *insertion_sort(i_array *ia)
{
	for (uint32_t i = 1; i < ia->size; i++) {
		int32_t tmp = ia->values[i];
		int32_t dec_idx = i - 1;
		while ((dec_idx >= 0) && (tmp < ia->values[dec_idx])) {
			ia->values[dec_idx + 1] =
				ia->values[dec_idx]; //shift value right
			dec_idx--; //shift idx left
		}
		ia->values[dec_idx + 1] = tmp;
	}

	return ia;
}
