#ifndef SEARCH_H
#define SEARCH_H

#include "i_array.h"
#include <stdbool.h>

#define NOT_FOUND -1

/**
 *
 * Binary Search
 *
 *  NOTE: This is a wrapper around the actual implementation. Upper and lower
 *  bound arguments are hidden from user. For simplicity, on failure -1 is
 *  being returned.
 *
 * Recursive implementation of binary search on an integer array.
 *
 * Invariants:
 * searchvalue >= ia->values[i] for all i > bottom
 * searchvalue < ia->values[i] for all i < top
 *
 * Internals:
 * @param ia a sorted i_array to search in
 * @param searchvalue specified integer, to search for
 * @param lower_b the lower bound of the array. 0 at initialization
 * @param upper_b the upper bound of the array.
 * @return the index of searchvalue inside the array, if exists, else upper_b.
 */
int32_t bin_search(i_array *ia, int32_t searchvalue);

#endif // !SEARCH_H
