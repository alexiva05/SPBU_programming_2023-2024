#include <iostream>

//Быстрая сортировка
int partition(int* arr, int left, int right) {
    int ptr1 = left;
    int ptr2 = right;
    int partition = arr[(left + right) / 2];

    while (ptr1 <= ptr2) {
        while (arr[ptr1] < partition) {
            ++ptr1;
        }
        while (arr[ptr2] > partition) {
            --ptr2;
        }
        if (ptr1 >= ptr2) {
            break;
        }
        std::swap(arr[ptr1++], arr[ptr2--]);
    }
    return ptr2;
}

void QuickSort(int* arr, int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        QuickSort(arr, left, p);
        QuickSort(arr, p + 1, right);
    }
}

//Сортировка вставками
void InsertionSort(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

//Пузырьковая сортировка
void BubbleSort(int* arr, int n) {
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        flag = false;
        for (int j = 0; j < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
                break;
        }
    }
}

//Сортировка выбором
void SelectionSort(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        int temp = arr[0];
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}