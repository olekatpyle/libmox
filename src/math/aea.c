#include "../../include/math.h"
#include <stdint.h>

uint64_t aea(uint64_t a, uint64_t b, int64_t *x, int64_t *y) {
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }

  int64_t x1, y1;
  uint64_t gcd = aea(b, a % b, &x1, &y1);
  *x = y1;
  *y = x1 - (a / b) * y1;
  return gcd;
}
