#include "sort.h"

void max_heapify(int *arr, int length, int index) {

  int largest = index;
  int left = 2 * index + 1, right = 2 * index + 2;
  if (left < length && arr[left] > arr[index]) {
    largest = left;
  }

  if (right < length && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != index) {
    int temp = arr[largest];
    arr[largest] = arr[index];
    arr[index] = temp;
    max_heapify(arr, length, largest);
  }
}

void build_max_heap(int *arr, int length) {
  for (int i = length / 2 - 1; i >= 0; i--) {
    max_heapify(arr, length, i);
  }
}

void heapsort(int *arr, int length) {
  build_max_heap(arr, length);

  int i = length - 1;
  while (i >= 0) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    i--;
    max_heapify(arr, i, 0);
  }
}

Test(sort, heapsort) {
  heapsort(arr, length);
  cr_expect(sorted(arr, length), "Heap sort not working");
}
