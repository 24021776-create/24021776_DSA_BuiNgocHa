void Insert(int a[], int &n, int x) {
    int i = n;
    a[n] = x;
    n++;

    // Đưa phần tử lên trên
    while (i > 0 && a[i] > a[(i - 1) / 2]) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}



void Delete(int a[], int &n, int x) {
    int k = -1;

    // Tìm vị trí phần tử cần xóa
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            k = i;
            break;
        }
    }

    if (k == -1) return;

    // Đổi với phần tử cuối
    swap(a[k], a[n - 1]);
    n--;

    // Kiểm tra với cha: nếu lớn hơn cha thì đi lên
    while (k > 0 && a[k] > a[(k - 1) / 2]) {
        swap(a[k], a[(k - 1) / 2]);
        k = (k - 1) / 2;
    }

    // Kiểm tra với con: nếu nhỏ hơn con thì đi xuống
    while (true) {
        int left = 2 * k + 1;
        int right = 2 * k + 2;
        int largest = k;

        if (left < n && a[left] > a[largest])
            largest = left;

        if (right < n && a[right] > a[largest])
            largest = right;

        if (largest == k) break;

        swap(a[k], a[largest]);
        k = largest;
    }
}
