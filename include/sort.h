#ifndef SORT_H
#define SORT_H

#include "i_array.h"

/**
 * Bubble sort algorithm
 *
 * @param ia the i_array struct to sort
 * @return pointer to sorted i_array
 */
i_array *bubble_sort(i_array *ia);

/**
 * Selection sort algorithm
 *
 * @param ia the i_array struct to sort
 * @return pointer to sorted i_array
 */
i_array *selection_sort(i_array *ia);

/**
 * Insertion sort algorithm
 *
 * @param ia the i_array struct to sort
 * @return pointer to sorted i_array
 */
i_array *insertion_sort(i_array *ia);

/**
 * Merge sort algorithm
 *
 * @param ia the i_array struct to sort
 * @return pointer to sorted i_array
 */
i_array *merge_sort(i_array *ia);

/**
 * Quick sort algorithm
 *
 * @param ia the i_array
 * @return pointer to sorted i_array
 * */
i_array *quick_sort(i_array *ia);
//-----------------------HELPER----------------------------------

/**
 * Helper function to swap to values inside i_array.
 *
 * @param ia the i_array struct to swap the values inside
 * @param left_for_swap the first value to swap
 * @param right_for_swap the second value to swap
 * @return nothing
 * */
void swap(i_array *ia, uint32_t left_for_swap, uint32_t right_for_swap);

#endif // !SORT_H
