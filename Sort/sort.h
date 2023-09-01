#pragma once

#include <criterion/criterion.h>
#include <stdio.h>

#define MAX_LENGTH 10000;
#define MAX_VALUE 100000000;

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
  printf("\n");
}

int *generate_arr(int length) {
  int *arr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++) {
    arr[i] = rand() % MAX_VALUE;
  }
  return arr;
}

int length;
int *arr;

void setup() {
  length = rand() % MAX_LENGTH;
  length += 1; // Why can't I add +1 in the previous line? Weird!!!!
  arr = generate_arr(length);
}

void teardown() { free(arr); }

TestSuite(sort, .init = setup, .fini = teardown);
