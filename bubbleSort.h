#pragma once
#include "print.h"

template <class T>
void bubbleSort(T arr, int size);

template <class T>
void bubbleSort(T arr, int size, std::ostream& output);

template <class T>
void bubbleSort(T arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j + 1 < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j +1]);
            }
        }
    }
}

template <class T>
void bubbleSort(T arr, int size, std::ostream& output) {
    //int iter= 0;
    output << "Source array:\n";
    print(arr, size, output);
    int iter_count = 0;
    int perm_count = 0;
    int start_time = clock();
    for (int i = 0; i < size; i++) {
        output << "Passage from " << i << "th to " << size - i << "th element\n";
        for (int j = 0; j + 1 < size - i - 1; j++) {
            iter_count++;
            output << "compare elements with indexes: " << j << " and " << j + 1 << '\n';
            if (arr[j] > arr[j + 1]) {
                output << "swap places: " << arr[j] << " and " << arr[j + 1] << '\n';
                std::swap(arr[j], arr[j + 1]);
                perm_count++;
                print(arr, size, output);
            }
            else {
                output << arr[j] << " and " << arr[j + 1] << " are ordered\n";
            }
        }
    }
    int finish_time = clock();
    double time = finish_time - start_time;
    output << "Sorting is finished\n";
    output << "It took: \n" << time << " ms\n" << iter_count << " iterations\n";
    output << perm_count << " permutations\n";
}


