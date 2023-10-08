#include "../include/bin_search.h"
#include "../include/i_array.h"
#include <criterion/criterion.h>

i_array *ia_sorted = NULL;
i_array *ia_unsorted = NULL;

void suitesetup(void)
{
	ia_sorted = ia_create(5);
	ia_push(ia_sorted, 1);
	ia_push(ia_sorted, 7);
	ia_push(ia_sorted, 69);
	ia_push(ia_sorted, 122);
	ia_push(ia_sorted, 136);

	ia_unsorted = ia_create(5);
	ia_push(ia_unsorted, 666);
	ia_push(ia_unsorted, 7);
	ia_push(ia_unsorted, 69);
	ia_push(ia_unsorted, 122);
	ia_push(ia_unsorted, 136);
}
void suiteteardown(void)
{
	ia_destroy(ia_sorted);
	ia_destroy(ia_unsorted);
}

TestSuite(binsearchtest, .init = suitesetup, .fini = suiteteardown);

Test(binsearchtest, find_element)
{
	cr_expect(bin_search(ia_sorted, 69) == 2,
		  "find_element: expected correct index to be found");
	cr_expect(bin_search(ia_sorted, 99) == -1,
		  "find_element: expected NOT_FOUND");
	cr_expect(bin_search(ia_unsorted, 69) == -1,
		  "find_element: expected NOT_FOUND");
}
