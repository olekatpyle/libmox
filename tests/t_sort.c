#include "../include/i_array.h"
#include "../include/sort.h"
#include "../src/util.h"
#include <criterion/criterion.h>
#include <stdlib.h>
#include <time.h>

i_array *ia = NULL;

void suitesetup(void)
{
	ia = ia_create(1000);
	for (uint32_t i = 0; i < ia->size; i++) {
		int r = rand() % 100;
		ia_push(ia, r);
	}
}

void suiteteardown(void)
{
	ia_destroy(ia);
}

TestSuite(sorttest, .init = suitesetup, .fini = suiteteardown);

Test(sorttest, swap)
{
	i_array *ia = ia_create(2);
	ia_push(ia, 2000);
	ia_push(ia, 4000);

	swap(ia, 0, 1);
	cr_expect(ia_get(ia, 0) == 4000, "ia_get: expected different value");
	cr_expect(ia_get(ia, 1) == 2000, "ia_get: expected different value");
}

Test(sorttest, bubblesort)
{
	ia = bubble_sort(ia);
	cr_expect(is_sorted(ia) == true,
		  "is_sorted: expected i_array to be sorted");
	//print_array(ia);
}

Test(sorttest, selectionsort)
{
	ia = selection_sort(ia);
	cr_expect(is_sorted(ia) == true,
		  "is_sorted: expected i_array to be sorted");
	//print_array(ia);
}

Test(sorttest, insertionsort)
{
	ia = insertion_sort(ia);
	cr_expect(is_sorted(ia) == true,
		  "is_sorted: expected i_array to be sorted");
	//print_array(ia);
}

Test(sorttest, mergesort)
{
	ia = merge_sort(ia);
	cr_expect(is_sorted(ia) == true,
		  "is_sorted: expected i_array to be sorted");
	//print_array(ia);
}

Test(sorttest, quicksort)
{
	ia = quick_sort(ia);
	cr_expect(is_sorted(ia) == true,
		  "is_sorted: expected i_array to be sorted");
	//print_array(ia);
}
