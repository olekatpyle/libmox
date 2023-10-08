#include "../include/i_array.h"
#include "../src/util.h"
#include <criterion/criterion.h>

i_array *ia = NULL;

void suitestartup(void)
{
	ia = ia_create(5);
	ia_push(ia, 1);
	ia_push(ia, 2);
	ia_push(ia, 3);
	ia_push(ia, 5);
	ia_push(ia, 9);
}

void suiteteardown(void)
{
	ia_destroy(ia);
}

TestSuite(iarraytest, .init = suitestartup, .fini = suiteteardown);

Test(iarraytest, push_elements)
{
	i_array *ia_new = ia_create(5);
	cr_expect(ia_push(ia_new, 1) == true, "ia_push: expected to succeed");
	cr_expect(ia_push(ia_new, 2) == true, "ia_push: expected to succeed");
	cr_expect(ia_push(ia_new, 7) == true, "ia_push: expected to succeed");
	cr_expect(ia_push(ia_new, 3) == true, "ia_push: expected to succeed");
	cr_expect(ia_push(ia_new, 7) == true, "ia_push: expected to succeed");
	cr_expect(ia_push(ia_new, 234256) == false,
		  "ia_push: expected to fail");
}

Test(iarraytest, set_get_element_at_idx)
{
	cr_expect(ia_set(ia, 4, 100) == true,
		  "ia_set: expected to return true");
	cr_expect(ia_set(ia, 2, 69) == true, "ia_set: expected to return true");
	cr_expect(ia_get(ia, 4) == 100,
		  "ia_get: expected to return correct value");
	cr_expect(ia_get(ia, 2) == 69,
		  "ia_get: expected to return correct value");
}

Test(iarraytest, is_sorted)
{
	cr_expect(is_sorted(ia) == true, "is_sorted: expected to succeed");
	ia_set(ia, 0, 1000);
	cr_expect(is_sorted(ia) == false, "is_sorted: expected to fail");
}

Test(iarraytest, equals)
{
	i_array *ib = ia_create(5);
	ia_push(ib, 1);
	ia_push(ib, 2);
	ia_push(ib, 3);
	ia_push(ib, 5);
	ia_push(ib, 9);

	i_array *ic = ia_create(5);
	ia_push(ic, 12354);
	ia_push(ic, 2);
	ia_push(ic, 652);
	ia_push(ic, 15);
	ia_push(ic, 9);

	i_array *id = ia_create(2);
	ia_push(id, 52);
	ia_push(id, 235);

	cr_expect(ia_equals(ia, ib) == true,
		  "ia_equals: expected both arrays to be equal");
	cr_expect(ia_equals(ib, ic) == false,
		  "ia_equals: expected both arrays to be different");
	cr_expect(ia_equals(ic, id) == false,
		  "ia_equals: expected both arrays to be different");

	ia_destroy(ib);
	ia_destroy(ic);
	ia_destroy(id);
}

Test(iarraytest, copy)
{
	i_array *i_cpy1 = ia_copy(ia);
	cr_expect(&ia != &i_cpy1);
	cr_expect(ia_equals(ia, i_cpy1) == true,
		  "ia_copy: expected both arrays to be a copy of each other");
	ia_set(i_cpy1, 3, 666);
	i_array *i_cpy2 = ia_copy(i_cpy1);
	cr_expect(&i_cpy1 != &i_cpy2);
	cr_expect(ia_equals(i_cpy1, i_cpy2) == true,
		  "ia_copy: expected both arrays to be a copy of each other");

	ia_destroy(i_cpy1);
	ia_destroy(i_cpy2);
}
