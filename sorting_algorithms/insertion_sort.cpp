#include <chrono>
#include <iostream>
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

void fill_array_with_random_int(int* arr, int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    arr[i] = rand();
  }
}

void print_array(int* arr, int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void print_test(int* arr, int arrLength) {
  cout << "Array before insertion sorting: ";

  print_array(arr, arrLength);

  auto start = chrono::high_resolution_clock::now();
  insertion_sort(arr, arrLength);
  auto stop = chrono::high_resolution_clock::now();

  cout << "Array after insertion sorting: ";
  print_array(arr, arrLength);

  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cout << "Duration: " << duration.count() << " microseconds" << endl;
  cout << endl;
}

int main() {
  // Test 1 (sorted array)
  int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_test(arr1, 10);

  // Test 2 (reverse array)
  int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  print_test(arr2, 10);

  // Test 3 (random array)
  int arr3[100] = {};
  fill_array_with_random_int(arr3, 100);
  print_test(arr3, 100);

  // Test 4 (large random array)
  int arr4[100000] = {};
  fill_array_with_random_int(arr4, 100000);
  print_test(arr4, 100000);

  // Test 5 (many arrays with different length)
  int* arr = nullptr;
  for (int arrSize = 1; arrSize < 200000; arrSize += 10000) {
    arr = new int[arrSize];

    fill_array_with_random_int(arr, arrSize);
    auto start = chrono::high_resolution_clock::now();
    insertion_sort(arr, arrSize);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Array length: " << arrSize << endl;
    cout << "Insertion sort time: " << duration.count() << " milliseconds"
         << endl;

    delete[] arr;
  }

  return 0;
}
