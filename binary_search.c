#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int size, int item, int* steps) {
  int bottom = 0;
  int top = size;
  *steps = 0;
  while (bottom <= top) {
    (*steps)++;
    int mid = (bottom + top) / 2;
    int guess = arr[mid];
    if (guess == item) {
      return mid;
    } else if (guess > item) {
      top = mid - 1;
    } else {
      bottom = mid + 1;
    }
  }
  return -1;
}

int simple_search(int arr[], int size, int item, int* steps) {
  for (int i = 0; i <= size; i++) {
    (*steps)++;
    if (item == arr[i])
      return i;
  }
  return -1;
}

int main() {
  int size = 10000000;
  int* arr = malloc(size * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation falied\n");
    return 1;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }

  int item = 730243;
  int steps = 0;

  // int res = binary_search(arr, size, item, &steps);
  int res = simple_search(arr, size, item, &steps);
  printf("The position of %d is %d in %d steps", item, res, steps);
  free(arr);

  return 0;
}
