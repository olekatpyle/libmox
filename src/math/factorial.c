#include "../../include/mmath.h"
#include <stdint.h>

uint64_t factorial(uint64_t n)
{
	if (n < 1)
		return 1;
	return n * factorial(n - 1);
}
