#pragma once

template <class T>
void shellSort(T* arr, int size);
template <class T>
void shellSort(T* arr, int size, std::ostream& output);

template <class T>
void shellSort(T* arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <class T>
void shellSort(T* arr, int size, std::ostream& output) {
    output << "Source array:\n";
    print(arr, size, output);
    //int iter_count = 0;
    int perm_count = 0;
    int start_time = clock();
    for (int gap = size / 2; gap > 0; gap /= 2) {
        output << "Gap: " << gap << '\n';
        for (int i = gap; i < size; i++) {
            T temp = arr[i];
            output << "Temp variable: " << temp << '\n';
            int j;
            output << "Going trought the array:\n";
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                perm_count++;
                print(arr, size, output);
            }
            arr[j] = temp;
            print(arr, size, output);
        }
    }
    int finish_time = clock();
    double time = finish_time - start_time;
    output << "Sorting is finished\n";
    //output << "It took: \n" << time << " ms\n" << iter_count << " iterations\n";
    output << "It took: \n" << time << " ms\n";
    output << perm_count << " permutations\n";
}