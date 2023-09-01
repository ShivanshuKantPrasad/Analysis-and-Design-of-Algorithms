#include "sort.h"
#include <stdlib.h>

void mergesort(int *start, int *end) {
  int length = end - start + 1;
  if (length == 1)
    return;

  int new_length = length / 2;
  mergesort(start, start + new_length - 1);
  mergesort(start + new_length, end);

  int *copy = malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++)
    copy[i] = start[i];
  int *right = copy;
  int *left = right + new_length;

  int i = 0;
  while (right < (copy + new_length) && left < (copy + length)) {
    if (*right < *left) {
      start[i] = *right;
      right++;
    } else {
      start[i] = *left;
      left++;
    }
    i++;
  }

  while (right < (copy + new_length)) {
    start[i] = *right;
    right++;
    i++;
  }

  while (left < (copy + length)) {
    start[i] = *left;
    left++;
    i++;
  }
  free(copy);
}

Test(sort, mergesort) {
  mergesort(arr, arr + length - 1);
  cr_expect(sorted(arr, length), "Merge sort not working");
}
