#pragma once

template <class T>
void quickSort(T* arr, int size);
template <class T>
void quickSort(T* arr, int stIdx, int endIdx);
template <class T>
int partition(T* arr, int stIdx, int endIdx);

template <class T>
void quickSort(T* arr, int size, std::ostream& output);
template <class T>
void quickSort(T* arr, int stIdx, int endIdx, std::ostream& output);
template <class T>
int partition(T* arr, int stIdx, int endIdx, std::ostream& output);

template <class T>
void quickSort(T* arr, int size) {
    quickSort(arr, 0, size - 1);
}

template <class T>
void quickSort(T* arr, int stIdx, int endIdx) {
    if (stIdx >= endIdx) {
        return;
    }
    int pivotIdx = partition(arr, stIdx, endIdx);
    quickSort(arr, stIdx, pivotIdx - 1);
    quickSort(arr, pivotIdx, endIdx);
}

template <class T>
int partition(T* arr, int stIdx, int endIdx) {
    T value = arr[endIdx];
    int posIdx = stIdx;
    for (int i = stIdx; i < endIdx; i++) {
        if (arr[i] <= value) {
            std::swap(arr[i], arr[posIdx]);

            posIdx++;
        }
    }
    arr[endIdx] = arr[posIdx];
    arr[posIdx] = value;
    return posIdx;
}

template <class T>
void quickSort(T* arr, int size, std::ostream& output) {

    quickSort(arr, 0, size - 1, output);
}

template <class T>
void quickSort(T* arr, int stIdx, int endIdx, std::ostream& output) {
    if (stIdx >= endIdx) {
        output << "Sorting is finished\n";
        return;
    }
    int pivotIdx = partition(arr, stIdx, endIdx, output);
    quickSort(arr, stIdx, pivotIdx - 1, output);
    quickSort(arr, pivotIdx, endIdx, output);
}

template <class T>
int partition(T* arr, int stIdx, int endIdx, std::ostream& output) {
    T value = arr[endIdx];
    output << "Reference value: " << value << '\n';
    int posIdx = stIdx;
    for (int i = stIdx; i < endIdx; i++) {
        output << "Compare element " << arr[i] << " with the reference element\n";
        if (arr[i] <= value) {
            output << "swap places: " << arr[i] << " and " << value << '\n';
            std::swap(arr[i], arr[posIdx]);
            print(arr, endIdx, output);
            posIdx++;
        }
        else {
            output << "Element " << arr[i] << " ordered\n";
        }
    }
    arr[endIdx] = arr[posIdx];
    arr[posIdx] = value;
    return posIdx;
}