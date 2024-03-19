#pragma once
#include "print.h"

//may be rename to cocktailSort?

template <class T>
void shakerSort(T arr, int size);

template <class T>
void shakerSort(T arr, int size, std::ostream& output);

template <class T>
void shakerSort(T arr, int size) {
    int left_idx = 0;
    int right_idx = size;
    bool is_sort = false;
    while (!is_sort) {
        is_sort = true;
        for (int i = left_idx; i < right_idx - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                is_sort = false;
                std::swap(arr[i], arr[i + 1]);
            }
        }
        right_idx--;
        for (int i = right_idx - 1; i > left_idx; i--) {
            if (arr[i - 1] > arr[i]) {
                is_sort = false;
                std::swap(arr[i - 1], arr[i]);
            }
        }
        left_idx++;
    }
}

template <class T>
void shakerSort(T arr, int size, std::ostream& output) {
    int left_idx = 0;
    int right_idx = size;
    int iter_count = 0;
    int perm_count = 0;
    bool is_sort = false;
    output << "Source array:\n";
    print(arr, size, output);
    int start_time = clock();
    while (!is_sort) {
        is_sort = true;
        output << "Passage from " << left_idx << "th to " << right_idx << "th element\n";
        for (int i = left_idx; i < right_idx - 1; i++) {
            iter_count++;
            output << "compare elements with indexes: " << i << " and " << i + 1 << '\n';
            if (arr[i] > arr[i + 1]) {
                output << "swap places: " << arr[i] << " and " << arr[i + 1] << '\n';
                is_sort = false;
                std::swap(arr[i], arr[i + 1]);
                perm_count++;
                print(arr, size, output);
            }
            else {
                output << arr[i] << " and " << arr[i + 1] << " are ordered\n";
            }
        }
        right_idx--;
        output << "Passage from " << right_idx << "th to " << left_idx << "th element\n";
        for (int i = right_idx - 1; i > left_idx; i--) {
            iter_count++;
            output << "compare elements with indexes: " << i << " and " << i + 1 << '\n';
            if (arr[i - 1] > arr[i]) {
                output << "swap places: " << arr[i] << " and " << arr[i + 1] << '\n';
                is_sort = false;
                std::swap(arr[i - 1], arr[i]);
                perm_count++;
                print(arr, size, output);
            }
            else {
                output << arr[i] << " and " << arr[i + 1] << " are ordered\n";
            }
        }
        left_idx++;
    }
    int finish_time = clock();
    double time = finish_time - start_time;
    output << "Sorting is finished\n";
    output << "It took: \n" << time << " ms\n" << iter_count << " iterations\n";
    output << perm_count << " permutations\n";
}