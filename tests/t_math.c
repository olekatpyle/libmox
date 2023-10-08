#include "../include/math.h"
#include <criterion/criterion.h>

Test(mathtest, factorial) {
  cr_expect(factorial(5) == 120, "factorial: expected correct answer");
  cr_expect(factorial(14) == 87178291200, "factorial: expected correct answer");
}

Test(mathtest, gcd) {
  cr_expect(gcd(3, 6) == 3, "gcd: expected correct answer");
  cr_expect(gcd(90, 27) == 9, "gcd: expected correct answer");
}

Test(mathtest, aea) {
  uint64_t gcd;
  int64_t k, l, *p_k = &k, *p_l = &l;
  gcd = aea(72, 5, p_k, p_l);
  cr_expect(gcd == 1, "aea: expected gcd to be 1");
  cr_expect(k == -2, "aea: expected different result");
  cr_expect(l == 29, "aea: expected different result");
  cr_expect(aea(72, 6, p_k, p_l) == 6, "aea: expected different result");
}

Test(mathtest, fibonacci) { cr_expect(fibonacci(15) == 610); }
