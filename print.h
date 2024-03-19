#pragma once

template <class T>
void print(T arr, int size);

template <class T>
void print(T arr, int size, std::ostream& output);

template <class T>
void print(T arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << " ]\n";
}

template <class T>
void print(T arr, int size, std::ostream& output) {
    output << "[";
    for (int i = 0; i < size; i++) {
        output << " " << arr[i];
    }
    output << " ]\n";
}