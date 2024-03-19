#pragma once

template <class T>
void mergeSort(T* arr, int size);

template <class T>
void merge(T* targArr, T* arr1, int size1, T* arr2, int size2);

template <class T>
void merge(T* targArr, T* arr1, int size1, T* arr2, int size2, std::ostream& output);

template <class T>
void mergeSort(T* arr, int size, std::ostream& output);

template <class T>
void mergeSort(T* arr, int size) {
    if (size == 1) {
        return;
    }
    int leftSize = size / 2;
    T* left = new int[leftSize];
    int rightSize = size - leftSize;
    T* right = new int[rightSize];
    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[i];
    }
    for (int i = 0; i < rightSize; i++) {
        right[i] = arr[i + leftSize];
    }
    mergeSort(left, leftSize);
    mergeSort(right, rightSize);
    merge(arr, left, leftSize, right, rightSize);
}

template <class T>
void merge(T* targArr, T* arr1, int size1, T* arr2, int size2) {
    int arr1MinIdx = 0;
    int arr2MinIdx = 0;
    int targArrMinIdx = 0;
    while (arr1MinIdx < size1 && arr2MinIdx < size2) {
        if (arr1[arr1MinIdx] <= arr2[arr2MinIdx]) {
            targArr[targArrMinIdx] = arr1[arr1MinIdx];
            arr1MinIdx++;
        }
        else {
            targArr[targArrMinIdx] = arr2[arr2MinIdx];
            arr2MinIdx++;
        }
        targArrMinIdx++;
    }
    while (arr1MinIdx < size1) {
        targArr[targArrMinIdx] = arr1[arr1MinIdx];
        arr1MinIdx++;
        targArrMinIdx++;
    }
    while (arr2MinIdx < size2) {
        targArr[targArrMinIdx] = arr2[arr2MinIdx];
        arr2MinIdx++;
        targArrMinIdx++;
    }
}

template <class T>
void mergeSort(T* arr, int size, std::ostream& output) {
    if (size == 1) {
        return;
        output << "Sorting is finished\n";
    }
    output << "Array to be split:\n";
    print(arr, size, output);
    int leftSize = size / 2;
    T* left = new int[leftSize];
    int rightSize = size - leftSize;
    T* right = new int[rightSize];
    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[i];
    }
    output << "Left subarray\n";
    print(left, leftSize, output);
    for (int i = 0; i < rightSize; i++) {
        right[i] = arr[i + leftSize];
    }
    output << "Right subarray\n";
    print(right, rightSize, output);
    mergeSort(left, leftSize, output);
    mergeSort(right, rightSize, output);
    merge(arr, left, leftSize, right, rightSize, output);
}

template <class T>
void merge(T* targArr, T* arr1, int size1, T* arr2, int size2, std::ostream& output) {
    int arr1MinIdx = 0;
    int arr2MinIdx = 0;
    int targArrMinIdx = 0;
    output << "Let's move on to the merger\n";
    output << "Arrays to merge:\n";
    print(arr1, size1, output);
    print(arr2, size2, output);
    while (arr1MinIdx < size1 && arr2MinIdx < size2) {
        if (arr1[arr1MinIdx] <= arr2[arr2MinIdx]) {
            targArr[targArrMinIdx] = arr1[arr1MinIdx];
            arr1MinIdx++;
        }
        else {
            targArr[targArrMinIdx] = arr2[arr2MinIdx];
            arr2MinIdx++;
        }
        targArrMinIdx++;
    }
    while (arr1MinIdx < size1) {
        targArr[targArrMinIdx] = arr1[arr1MinIdx];
        arr1MinIdx++;
        targArrMinIdx++;
    }
    while (arr2MinIdx < size2) {
        targArr[targArrMinIdx] = arr2[arr2MinIdx];
        arr2MinIdx++;
        targArrMinIdx++;
    }
    output << "Array after merge:\n";
    print(targArr, size1 + size2, output);
}