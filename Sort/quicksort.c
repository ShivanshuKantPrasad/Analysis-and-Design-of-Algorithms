#include "sort.h"
#include <stdlib.h>

void quicksort(int *start, int *end) {
  int length = end - start + 1;
  if (length <= 1)
    return;

  int pivot = *end;
  int *right = malloc(sizeof(int) * length);
  int *left = malloc(sizeof(int) * length);

  int rIndex = 0;
  int lIndex = 0;
  for (int *index = start; index < end; index++) {
    if (*index < pivot) {
      left[lIndex] = *index;
      lIndex++;
    } else {
      right[rIndex] = *index;
      rIndex++;
    }
  }

  quicksort(left, left + lIndex - 1);
  quicksort(right, right + rIndex - 1);

  int *index = start;
  int i = 0;
  while (i < lIndex) {
    *index = left[i];
    index++;
    i++;
  }

  *index = pivot;
  index++;

  i = 0;
  while (i < rIndex) {
    *index = right[i];
    index++;
    i++;
  }

  free(left);
  free(right);
}

Test(sort, quicksort) {
  quicksort(arr, arr + length - 1);
  cr_expect(sorted(arr, length), "Merge sort not working");
}
