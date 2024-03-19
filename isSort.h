#pragma once

template <class T>
bool isSort(T arr, int size);

template <class T>
bool isSort(T arr, int size, std::ostream& output);

template <class T>
bool isSort(T arr, int size) {
    bool is_sort = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return is_sort;
}

template <class T>
bool isSort(T arr, int size, std::ostream& output) {
    bool is_sort = true;
    for (int i = 0; i < size - 1; i++) {
        output << "Compare elements with indexes: " << i << " and " << i + 1 << '\n';
        if (arr[i] > arr[i + 1]) {
            output << "Unsorted elements found: " << arr[i] << " > " << arr[i + 1] << '\n';
            return false;
        }
        output << "All right, " << arr[i] << " < " << arr[i + 1] << '\n';
    }
    output << "All elements are sorted\n";
    return is_sort;
}