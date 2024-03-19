#pragma once

template <class T>
void combSort(T arr, int size);

template <class T>
void combSort(T arr, int size, std::ostream& output);

template <class T>
void combSort(T arr, int size) {
    const double Factor = 1.247;
    int step = size - 1;
    while (step >= 1) {
        for (int i = 0; i + step < size; i++) {
            if (arr[i] > arr[i + step]) {
                std::swap(arr[i], arr[i + step]);
            }
        }
        step = step / Factor;
    }
}

template <class T>
void combSort(T arr, int size, std::ostream& output) {
    const double Factor = 1.247;
    int step = size - 1;
    int iter = 0;
    output << "Source array:\n";
    print(arr, size, output);
    int iter_count = 0;
    int perm_count = 0;
    int start_time = clock();
    while (step >= 1) {
        output << "Step:" << step << '\n';
        for (int i = 0; i + step < size; i++) {
            iter_count++;
            output << "compare elements with indexes: " << i << " and " << i + step << '\n';
            if (arr[i] > arr[i + step]) {
                output << "swap places: " << arr[i] << " and " << arr[i + step] << '\n';
                perm_count++;
                std::swap(arr[i], arr[i + step]);
                print(arr, size, output);
            }
            else {
                output << arr[i] << " and " << arr[i + step] << " are ordered\n";
            }
        }
        step = step / Factor;
    }
    int finish_time = clock();
    double time = finish_time - start_time;
    output << "Sorting is finished\n";
    output << "It took: \n" << time << " ms\n" << iter_count << " iterations\n";
    output << perm_count << " permutations\n";
}
