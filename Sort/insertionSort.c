void insertion(int *arr, int length) {
  for (int *i = arr + 1; i < arr + length; i++) {
    int key = *i;
    int *j = i - 1;
    for (; j >= arr && *j > key; j--) {
      *(j + 1) = *j;
    }
    *(j + 1) = key;
  }
}
