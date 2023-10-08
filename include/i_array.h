#ifndef I_ARRAY_H
#define I_ARRAY_H

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

/**
 * Abstract data structure - i_array
 *
 * @property size, also max_size of the array
 * @property num_entries, number of entries, inside the array
 * @property values, internal integer array to store values
 */
typedef struct {
  uint32_t size, num_entries;
  int32_t *values;
} i_array;

/**
 * Constructor for i_array struct.
 *
 * @param max_size - specify the length of the array
 * @return i_array* - i_array* pointer to created array
 * */
i_array *ia_create(uint32_t max_size);

/**
 * Deconstructor for i_array struct.
 * Should always be called afterwards in order to free memory.
 *
 * @param *ia - pointer to i_array, you wish to deconstruct.
 * @return void
 * */
void ia_destroy(i_array *ia);

/**
 * Function to push element to next free index in i_array, in general at the
 * end.
 *
 * @param *ia - the i_array struct to add element to
 * @param value - the value to store
 * @return bool - true on success, else false
 * */
bool ia_push(i_array *ia, int32_t value);

/**
 * Function, to set the value in an i_array struct at specified index.
 *
 * @param *ia -  the i_array struct, to set the value at specified index
 * @param idx - the index to put value at
 * @param value - the value to put at index
 * @return bool - true on success, false, if index is out of bounds
 * */
bool ia_set(i_array *ia, uint32_t idx, int32_t value);

/**
 * Function, to get value of i_array at specified index.
 *
 * @param ia - the i_array struct to get the value from
 * @param idx - the index of the value to get from i_array
 * @return int - the value found at specified position or -1 if out of bounds
 * */
int ia_get(i_array *ia, uint32_t idx);

/**
 * Function, to copy an i_array.
 *
 * @param ia the i_array to copy
 * @return i_array* - pointer to the copy of ia
 * */
i_array *ia_copy(i_array *ia);

/**
 * Function, to check if two provided i_arrays are equal copies of each other.
 *
 * @param ia - first i_array to compare
 * @param ib - second i_array to compare
 * return bool - true if arrays are equal copies of each other, else false
 * */
bool ia_equals(i_array *ia, i_array *ib);

/**
 * Function, to print the i_array struct to stdout.
 *
 * @param ia - the i_array struct to print to stdout
 * @return void
 * */
void ia_print(i_array *ia);

#endif // !I_ARRAY_H
