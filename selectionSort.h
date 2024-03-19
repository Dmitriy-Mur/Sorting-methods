#pragma once

template <class T>
void selectionSort(T arr, int size);

template <class T>
void selectionSort(T arr, int size, std::ostream& output);

template <class T>
void selectionSort(T arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[min_idx], arr[i]);
        }
    }
}

template <class T>
void selectionSort(T arr, int size, std::ostream& output) {
    output << "Source array:\n";
    print(arr, size, output);
    int iter_count = 0;
    int perm_count = 0;
    int start_time = clock();
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        output << "Index of the current minimum element " << min_idx << '\n';
        for (int j = i + 1; j < size; j++) {
            iter_count++;
            output << "compare elements with indexes: " << min_idx << " and " << j << '\n';
            if (arr[min_idx] > arr[j]) {
                output << "Now the index of the current smallest element " << j << '\n';
                min_idx = j;
            }
            else {
                output << arr[min_idx] << " and " << arr[j] << " are ordered\n";
            }
        }
        if (min_idx != i) {
            output << "swap places: " << arr[min_idx] << " and " << arr[i] << '\n';
            std::swap(arr[min_idx], arr[i]);
            print(arr, size, output);
            perm_count++;
        }
    }
    int finish_time = clock();
    double time = finish_time - start_time;
    output << "Sorting is finished\n";
    output << "It took: \n" << time << " ms\n" << iter_count << " iterations\n";
    output << perm_count << " permutations\n";
}
