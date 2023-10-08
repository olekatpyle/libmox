#include "../../include/mmath.h"
#include <stdint.h>

uint64_t gcd(uint64_t a, uint64_t b)
{
	if (a == b)
		return a;

	if (a > b)
		return gcd(a - b, b);
	else
		return gcd(a, b - a);
}
