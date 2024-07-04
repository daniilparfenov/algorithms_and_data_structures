#include <iostream>

#include "func_for_tests.cpp"
using namespace std;

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void selection_sort(int* arr, int arrSize) {
  int indexOfMin = 0;
  for (int i = 0; i < arrSize - 1; i++) {
    indexOfMin = i;
    for (int j = i + 1; j < arrSize; j++) {
      if (arr[j] < arr[indexOfMin]) {
        indexOfMin = j;
      }
    }
    swap(&arr[i], &arr[indexOfMin]);
  }
}

int main() {
  // Test 1 (sorted array)
  int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_test(arr1, 10, selection_sort);

  // Test 2 (reverse array)
  int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  print_test(arr2, 10, selection_sort);

  // Test 3 (random array)
  int arr3[100] = {};
  fill_array_with_random_int(arr3, 100);
  print_test(arr3, 100, selection_sort);

  // // Test 4 (huge random array)
  int arr4[100000] = {};
  fill_array_with_random_int(arr4, 100000);
  print_test(arr4, 100000, selection_sort);

  // // Test 5 (many arrays with different length)
  print_huge_test(selection_sort);

  return 0;
}
