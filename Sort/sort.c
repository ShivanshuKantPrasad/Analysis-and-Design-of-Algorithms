#include "insertionSort.c"
#include <criterion/criterion.h>
#include <stdio.h>

bool sorted(int *arr, int length) {
  for (int i = 0; i < length - 1; i++) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

void print_arr(int *arr, int length) {
  for (int *i = arr; i < (arr + length); i++)
    printf("%d, ", *i);
}

int *generate_arr(int length) {
  int *arr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++) {
    arr[i] = rand();
  }
  return arr;
}

Test(sample, test) {
  int length = rand() % 100 + 1;
  int *arr = generate_arr(length);
  insertion(arr, length);
  cr_expect(sorted(arr, length), "Insertion sort not working");
}
