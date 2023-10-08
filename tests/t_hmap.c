#include "../include/hashmap.h"
#include <criterion/criterion.h>
#include <stdio.h>

hash_map *hm = NULL;
void suitesetup(void)
{
	hm = hmap_create(10, NULL, NULL);
	hmap_insert(hm, "hello", "test");
	hmap_print(hm);
}
void suiteteardown(void)
{
	hmap_destroy(hm);
}

TestSuite(hmaptest, .init = suitesetup, .fini = suiteteardown);

Test(hmaptest, create)
{
	hash_map *hm_test = hmap_create(1000, NULL, NULL);
	//cr_expect(hm_test != NULL, "hmap_create: expected not null");
	hmap_destroy(hm_test);
}
