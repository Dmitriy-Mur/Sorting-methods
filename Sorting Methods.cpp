#include <iostream>
#include <fstream>
#include "bubbleSort.h"
#include "findMax.h"
#include "findMin.h"
#include "print.h"
#include "fill.h"
#include "shakerSort.h"
#include "combSort.h"
#include "print.h"
#include "isSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "countSort.h"
using namespace std;

//template <class T>
//void bucketSort(T* arr, int size);

int main(int argc, char** argv) {
    srand(time(0));
    system("chcp 1251>null");
    int size = 25;
    int* arr = new int[size];
    fill(arr, size, 0, 100);

   fstream output;
    output.open("Bubble sort.txt");
    bubbleSort(arr, size, output);
    output.close();
    system("notepad.exe Bubble sort.txt");

    fstream output1;
    output1.open("Shaker sort.txt");
    shakerSort(arr, size, output1);
    output1.close();
    system("notepad.exe Shaker sort.txt");

    fstream output2;
    output2.open("Comb sort.txt");
    combSort(arr, size, output2);
    output2.close();
    system("notepad.exe Comb sort.txt");

    fstream output3;
    output3.open("Selection sort.txt");
    selectionSort(arr, size, output3);
    output3.close();
    system("notepad.exe Selection sort.txt");

    fstream output4;
    output4.open("Insertion sort.txt");
    insertionSort(arr, size, output4);
    output4.close();
    system("notepad.exe Insertion sort.txt");

    fstream output5;
    output5.open("Quick sort.txt");
    quickSort(arr, size, output5);
    output5.close();
    system("notepad.exe Quick sort.txt");

    fstream output6;
    output6.open("Merge sort.txt");
    mergeSort(arr, size, output6);
    output6.close();
    system("notepad.exe Merge sort.txt");

    fill(arr, size, 0, 5);

    fstream output7;
    output7.open("Count sort.txt");
    countSort(arr, size, output7);
    output7.close();
    system("notepad.exe Count sort.txt");

    return 0;
}

//template <class T>
//void bucketSort(T* arr, int size) {
//    T minVal = findMin(arr, size);
//    T maxVal = findMax(arr, size);
//    int bucketsCount = (int) ((maxVal - minVal) / size) + 1;
//    T** buckets = new T * [bucketsCount];
//    for (int i = 0; i < bucketsCount; i++) {
//        buckets[i] = new T[size];
//    }
//    for (int i = 0; i < size; i++) {
//        int bucketIdx = (arr[i] - minVal) / size;
//        buckets[bucketIdx][i] = arr[i];
//    }
//    int idx = 0;
//    for (auto& bucket : buckets) {
//        for (int num : bucket) {
//            arr[idx++] = num;
//        }
//    }
//}