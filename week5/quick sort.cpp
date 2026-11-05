#include <iostream>
using namespace std;

int Partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);

    return i + 1;
}

void QuickSort(int a[], int l, int r) {
    if (l < r) {
        int p = Partition(a, l, r);

        QuickSort(a, l, p - 1);
        QuickSort(a, p + 1, r);
    }
}
