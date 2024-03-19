#pragma once

template <class T>
void insertionSort(T arr, int size);

template <class T>
void insertionSort(T arr, int size, std::ostream& output);

template <class T>
void insertionSort(T arr, int size) {
    for (int i = 1; i < size; i++) {
        int sorted = i - 1;
        while (sorted >= -1 and (arr[sorted] > arr[sorted + 1])) {
            std::swap(arr[sorted], arr[sorted + 1]);
            sorted--;
        }
    }
}

template <class T>
void insertionSort(T arr, int size, std::ostream& output) {
    output << "Source array:\n";
    print(arr, size, output);
    int iter_count = 0;
    int perm_count = 0;
    int start_time = clock();
    for (int i = 1; i < size; i++) {
        int sorted = i - 1;
        output << "the array is sorted to the " << i << "th element\n";
        output << "compare elements with indexes: " << sorted << " and " << sorted + 1 << '\n';
        while (sorted >= -1 and (arr[sorted] > arr[sorted + 1])) {
            output << "swap places: " << arr[sorted] << " and " << arr[sorted + 1] << '\n';
            std::swap(arr[sorted], arr[sorted + 1]);
            perm_count++;
            print(arr, size, output);
            sorted--;
            iter_count++;
        }
        iter_count++;
    }
    int finish_time = clock();
    double time = finish_time - start_time;
    output << "Sorting is finished\n";
    output << "It took: \n" << time << " ms\n" << iter_count << " iterations\n";
    output << perm_count << " permutations\n";
}
