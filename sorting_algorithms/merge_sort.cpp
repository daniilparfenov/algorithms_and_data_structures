#include <climits>
#include <iostream>

#include "func_for_tests.cpp"

void merge(int* arr, int s, int sep, int f) {
  int lSize = sep - s + 1;
  int rSize = f - sep;

  int* leftArr = new int[lSize + 1];
  int* rightArr = new int[rSize + 1];

  for (int i = 0; i < lSize; i++) {
    leftArr[i] = arr[s + i];
  }
  for (int i = 0; i < rSize; i++) {
    rightArr[i] = arr[sep + i + 1];
  }

  leftArr[lSize] = INT_MAX;
  rightArr[rSize] = INT_MAX;

  int l = 0, r = 0;

  for (int i = 0; i < f - s + 1; i++) {
    if (leftArr[l] < rightArr[r]) {
      arr[s + i] = leftArr[l];
      l++;
    } else {
      arr[s + i] = rightArr[r];
      r++;
    }
  }
  delete[] leftArr;
  delete[] rightArr;
}

void merge_sort_recursion(int* arr, int s, int f) {
  if (f - s + 1 > 1) {
    int sep = (s + f) / 2;
    merge_sort_recursion(arr, s, sep);
    merge_sort_recursion(arr, sep + 1, f);
    merge(arr, s, sep, f);
  }
}

void merge_sort(int* arr, int arrSize) {
  merge_sort_recursion(arr, 0, arrSize - 1);
}

int main() {
  // Test 1 (sorted array)
  int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_test(arr1, 10, merge_sort);

  // Test 2 (reverse array)
  int arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  print_test(arr2, 10, merge_sort);

  // Test 3 (random array)
  int arr3[100] = {};
  fill_array_with_random_int(arr3, 100);
  print_test(arr3, 100, merge_sort);

  // Test 4 (large random array)
  int arr4[100000] = {};
  fill_array_with_random_int(arr4, 100000);
  print_test(arr4, 100000, merge_sort);

  // Test 5 (many arrays with different length)
  print_huge_test(merge_sort);

  // Extra Test (100 million elements array)
  // int arrSize = 100000000;
  // int* arr = new int[arrSize];
  // fill_array_with_random_int(arr, arrSize);
  // print_test(arr, arrSize, merge_sort, false);

  return 0;
}