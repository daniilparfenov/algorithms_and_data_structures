#pragma once
#include <chrono>
#include <climits>
#include <iostream>
using namespace std;

void fill_array_with_random_int(int* arr, int arrLength, int mod = INT_MAX) {
  for (int i = 0; i < arrLength; i++) {
    arr[i] = rand() % mod;
  }
}

void print_array(int* arr, int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void print_test(int* arr, int arrLength, void ownSort(int* arr, int arrSize),
                bool printArr = true) {
  if (printArr) {
    cout << "Array before sorting: ";
    print_array(arr, arrLength);
  }

  auto start = chrono::high_resolution_clock::now();
  ownSort(arr, arrLength);
  auto stop = chrono::high_resolution_clock::now();

  if (printArr) {
    cout << "Array after sorting: ";
    print_array(arr, arrLength);
  }

  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  cout << "Duration: " << duration.count() << " milliseconds" << endl;
  cout << endl;
}

void print_huge_test(void ownSort(int* arr, int arrSize)) {
  int* arr = nullptr;
  for (int arrSize = 1; arrSize < 200002; arrSize += 10000) {
    arr = new int[arrSize];

    fill_array_with_random_int(arr, arrSize);
    auto start = chrono::high_resolution_clock::now();
    ownSort(arr, arrSize);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Array length: " << arrSize << endl;
    cout << "Sort time: " << duration.count() << " milliseconds" << endl;

    delete[] arr;
  }
}