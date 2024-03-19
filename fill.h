#pragma once

template <class T>
void fill(T arr, int size, std::istream& intput) {
    for (int i = 0; i < size; i++) {
        std::cout << "Enter elem number " << i << "/" << size << ": ";
        intput >> arr[i];
    }
}

template <class T>
void fill(T arr, int size, int mn, int mx) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (mx - mn + 1) + mn;
    }
}
