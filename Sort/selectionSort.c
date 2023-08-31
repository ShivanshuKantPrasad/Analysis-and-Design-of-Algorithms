void selection(int *arr, int length) {
  int i = 0, j = 0;
  for (int i = 0; i < length - 1; i++) {
    int jMin = i;
    for (int j = 0; j < length; j++) {
      if (arr[j] < arr[jMin]) {
        jMin = j;
      }
    }
    if (jMin != 1) {
      int temp = arr[i];
      arr[i] = arr[jMin];
      arr[jMin] = arr[i];
    }
  }
}
