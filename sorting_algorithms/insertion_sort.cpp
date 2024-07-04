#include <iostream>

#include "func_for_tests.cpp"
using namespace std;

void insertion_sort(int* arr, int arrLength) {
  int key = 0;
  int j = 0;

  for (int i = 1; i < arrLength; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] >= key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  // Test 1 (sorted array)
  int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_test(arr1, 10, insertion_sort);

  // Test 2 (reverse array)
  int arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  print_test(arr2, 10, insertion_sort);

  // Test 3 (random array)
  int arr3[100] = {};
  fill_array_with_random_int(arr3, 100);
  print_test(arr3, 100, insertion_sort);

  // // Test 4 (large random array)
  int arr4[100000] = {};
  fill_array_with_random_int(arr4, 100000);
  print_test(arr4, 100000, insertion_sort);

  // Test 5 (many arrays with different length)
  print_huge_test(insertion_sort);

  return 0;
}
