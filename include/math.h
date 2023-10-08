#ifndef MATH_H
#define MATH_H

#include <stdint.h>

/**
 * Calculate factorial.
 *
 * @param n integer number to calculate the factorial of
 * @return the factorial of int n
 *
 * */
uint64_t factorial(uint64_t n);

/**
 * Greatest common divisor. Euklidean algorithm.
 *
 * @param a first integer
 * @param b second integer
 * @return greatest common divisor of a and b
 *
 * */
uint64_t gcd(uint64_t a, uint64_t b);

/**
 * Advanced euklidean algorithm.
 *
 * @param a first integer to find the greatest common divisor of
 * @param b second integer to find the greatest common divisor of
 * @param k pointer to integer to store result outside of function
 * @param l pointer to integer to store result outside of function
 * @return the greatest common divisor
 *
 * */
uint64_t aea(uint64_t a, uint64_t b, int64_t *k, int64_t *l);

/**
 * Calculate the nth fibonacci number. This implementation assumes the sequence
 * starts with 1. -> 1 1 2 3 5 ...
 *
 * @param n integer to indicate which fibonacci number to calculate
 * @return the nth fibonacci number
 * */
uint64_t fibonacci(uint64_t n);

#endif // !MATH_H
