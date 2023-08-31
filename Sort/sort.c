#include "insertionSort.c"
#include "selectionSort.c"
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

int length;
int *arr;

void setup() {
  length = rand() % 100 + 1;
  arr = generate_arr(length);
}

void teardown() { free(arr); }

TestSuite(sort, .init = setup, .fini = teardown);

Test(sort, insertion) {
  insertion(arr, length);
  cr_expect(sorted(arr, length), "Insertion sort not working");
}

Test(sort, selection) {
  selection(arr, length);
  cr_expect(sorted(arr, length), "Selection sort not working");
}
