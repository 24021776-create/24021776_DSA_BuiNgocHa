//Max Heap
void Heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n) {

    // B1: Xây dựng Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, n, i);
    }

    // B2: Đưa phần tử lớn nhất về cuối
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);

        // B3: Điều chỉnh lại Heap
        Heapify(a, i, 0);
    }
}

//Min Heap
void Heapify(int a[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        Heapify(a, n, smallest);
    }
}

void HeapSort(int a[], int n) {

    // Xây dựng Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);

    // Đưa phần tử nhỏ nhất về cuối
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}



