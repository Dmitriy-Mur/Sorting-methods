#pragma once
#include "findMax.h"
#include "findMin.h"

template <class T>
void countSort(T* arr, int size);

template <class T>
void countSort(T* arr, int size, T minVal, T maxVal);

template <class T>
void countSort(T* arr, int size, std::ostream& output);

template <class T>
void countSort(T* arr, int size, T minVal, T maxVal, std::ostream& output);

template <class T>
void countSort(T* arr, int size) {
    T minVal = findMin(arr, size);
    T maxVal = findMax(arr, size);
    countSort(arr, size, minVal, maxVal);
}

template <class T>
void countSort(T* arr, int size, T minVal, T maxVal) {
    int supArrSize = maxVal + 1 - minVal;
    T* supArr = new int[supArrSize] {0};
    for (int i = 0; i < size; i++) {
        supArr[arr[i]]++;
    }
    int idx = 0;
    for (int i = 0; i < supArrSize; i++) {
        while (supArr[i] > 0) {
            arr[idx] = i;
            idx++;
            supArr[i]--;
        }
    }
    delete[] supArr;
}

template <class T>
void countSort(T* arr, int size, std::ostream& output) {
    T minVal = findMin(arr, size);
    T maxVal = findMax(arr, size);
    output << "Minimum array element:" << minVal << '\n';
    output << "Maximum array element:" << maxVal << '\n';
    countSort(arr, size, minVal, maxVal, output);
}

template <class T>
void countSort(T* arr, int size, T minVal, T maxVal, std::ostream& output) {
    int supArrSize = maxVal + 1 - minVal;
    T* supArr = new int[supArrSize] {0};
    for (int i = 0; i < size; i++) {
        supArr[arr[i]]++;
    }
    int idx = 0;
    for (int i = 0; i < supArrSize; i++) {
        output << "\"" << i << "\" appeared " << supArr[i] << " times in the array\n";
        while (supArr[i] > 0) {
            arr[idx] = i;
            idx++;
            supArr[i]--;
        }
    }
    delete[] supArr;
    print(arr, size, output);
}

