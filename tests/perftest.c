#include "../include/i_array.h"
#include "../include/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 9
#define ARRAY_SIZE 10000
uint32_t LOOPS;

double calc_average(double *t_results) {
  double average = 0;
  for (uint32_t i = 0; i < LOOPS; i++) {
    average += t_results[i];
  }
  return average / LOOPS;
}

double calc_improvement(double base, double time) {
  return (base - time) / base * 100;
}

int main(int argc, char *argv[]) {
  if (argc == 2) {
    LOOPS = atoi(argv[1]);
    // in case of nonsense
    if (LOOPS == 0)
      LOOPS = 1;
    else if (LOOPS > LIMIT)
      LOOPS = LIMIT;
  } else
    LOOPS = 3;

  uint32_t i;

  // time captures
  int64_t before, after;

  // arrays to hold the calculated times for each run for every algorithm
  double t_bubble[LOOPS], t_select[LOOPS], t_insert[LOOPS], t_merge[LOOPS],
      t_quick[LOOPS];

  // init randomized array to sort
  for (i = 0; i < LOOPS; i++) {
    i_array *orig = ia_create(ARRAY_SIZE);
    for (uint32_t j = 0; j < orig->size; j++) {
      uint32_t r = rand() % 1000;
      ia_push(orig, r);
    }

    ia_print(orig);
    for (uint32_t i = 0; i < orig->size; i++) {
      printf("%u, ", ia_get(orig, i));
    }
    // create deep copies of the original array
    i_array *ia_bubble = ia_copy(orig);
    i_array *ia_select = ia_copy(orig);
    i_array *ia_insert = ia_copy(orig);
    i_array *ia_merge = ia_copy(orig);
    i_array *ia_quick = ia_copy(orig);

    // sort and capture
    before = clock();
    bubble_sort(ia_bubble);
    after = clock();
    t_bubble[i] = (double)(after - before) / CLOCKS_PER_SEC;

    before = clock();
    selection_sort(ia_select);
    after = clock();
    t_select[i] = (double)(after - before) / CLOCKS_PER_SEC;

    before = clock();
    insertion_sort(ia_insert);
    after = clock();
    t_insert[i] = (double)(after - before) / CLOCKS_PER_SEC;

    before = clock();
    merge_sort(ia_merge);
    after = clock();
    t_merge[i] = (double)(after - before) / CLOCKS_PER_SEC;

    before = clock();
    quick_sort(ia_quick);
    after = clock();
    t_quick[i] = (double)(after - before) / CLOCKS_PER_SEC;

    // cleanup
    ia_destroy(orig);
    ia_destroy(ia_bubble);
    ia_destroy(ia_select);
    ia_destroy(ia_insert);
    ia_destroy(ia_merge);
    ia_destroy(ia_quick);
  }

  // statistics
  double base = calc_average(t_bubble);
  double ave_select = calc_average(t_select);
  double ave_insert = calc_average(t_insert);
  double ave_merge = calc_average(t_merge);
  double ave_quick = calc_average(t_quick);

  // print results
  printf("\n\nPerformance test results - sorting\n\n");
  printf("RUN\t\t| ");
  for (i = 0; i < LOOPS; i++)
    printf("#%d\t\t| ", i + 1);
  printf("MID\t\t| Improvement (over slowest)\n----------------+");
  for (i = 0; i < LOOPS + 1; i++)
    printf("---------------+");
  printf("---------------------------\nBubblesort\t|");
  for (i = 0; i < LOOPS; i++)
    printf("%fs\t| ", t_bubble[i]);
  printf("%fs\t| slowest\n", base);
  printf("Selectionsort\t|");
  for (i = 0; i < LOOPS; i++)
    printf("%fs\t| ", t_select[i]);
  printf("%fs\t| %.1f%%\n", ave_select, calc_improvement(base, ave_select));
  printf("Insertsort\t|");
  for (i = 0; i < LOOPS; i++)
    printf("%fs\t| ", t_insert[i]);
  printf("%fs\t| %.1f%%\n", ave_insert, calc_improvement(base, ave_insert));
  printf("Mergesort\t|");
  for (i = 0; i < LOOPS; i++)
    printf("%fs\t| ", t_merge[i]);
  printf("%fs\t| %.1f%%\n", ave_merge, calc_improvement(base, ave_merge));
  printf("Quicksort\t|");
  for (i = 0; i < LOOPS; i++)
    printf("%fs\t| ", t_quick[i]);
  printf("%fs\t| %.1f%%\n", ave_quick, calc_improvement(base, ave_quick));

  return 0;
}
