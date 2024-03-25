#pragma once
#include <iostream>

template <class T>
void bucketSort(T* arr, int size);
template <class T>
void bucketSort(T* arr, int size, std::ostream& output);

template <class T>
void bucketSort(T* arr, int size) {
    T minVal = findMin(arr, size);
    T maxVal = findMax(arr, size);
    int bucketsCount = (int)((maxVal - minVal) / size) + 1;
    T** buckets = new T * [bucketsCount];
    for (int i = 0; i < bucketsCount; i++) {
        buckets[i] = new T[size]();
    }
    for (int i = 0; i < size; i++) {
        int bucketIdx = (arr[i] - minVal) / size;
        buckets[bucketIdx][i] = arr[i];
    }
    int idx = 0;
    for (int i = 0; i < bucketsCount; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j] != 0) {
                arr[idx++] = buckets[i][j];
            }
        }
    }
    for (int i = 0; i < bucketsCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
}

template <class T>
void bucketSort(T* arr, int size, std::ostream& output) {
    T minVal = findMin(arr, size);
    T maxVal = findMax(arr, size);
    int bucketsCount = (int)((maxVal - minVal) / size) + 1;
    T** buckets = new T * [bucketsCount];
    for (int i = 0; i < bucketsCount; i++) {
        buckets[i] = new T[size]();
    }
    for (int i = 0; i < size; i++) {
        int bucketIdx = (arr[i] - minVal) / size;
        buckets[bucketIdx][i] = arr[i];
    }
    output << "Buckets:\n";
    for (int i = 0; i < bucketsCount; i++) {
        print(buckets[i], size, output);
    }
    int idx = 0;
    for (int i = 0; i < bucketsCount; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j] != 0) {
                arr[idx++] = buckets[i][j];
            }
        }
    }
    for (int i = 0; i < bucketsCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
}