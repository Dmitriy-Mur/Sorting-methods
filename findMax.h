#pragma once

template <class T>
T findMax(T* arr, int size) {
    T result = arr[0];
    for (int i = 1; i < size; i++) {
        if (result < arr[i]) {
            result = arr[i];
        }
    }
    return result;
}


