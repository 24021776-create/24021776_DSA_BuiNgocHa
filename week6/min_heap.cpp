void Insert(int a[], int &n, int x) {
    int i = n;
    a[n] = x;
    n++;

    while (i > 0 && a[i] < a[(i - 1) / 2]) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void Delete(int a[], int &n, int x) {
    int k = -1;

    // B1: Tìm phần tử cần xóa
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            k = i;
            break;
        }
    }

    if (k == -1) return;

    // B2: Đổi với phần tử cuối và xóa
    swap(a[k], a[n - 1]);
    n--;

    // B3: Kiểm tra với cha
    if (k > 0 && a[k] < a[(k - 1) / 2]) {
        while (k > 0 && a[k] < a[(k - 1) / 2]) {
            swap(a[k], a[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }
    else {
        // B4: Kiểm tra với con nhỏ nhất
        while (true) {
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            int smallest = k;

            if (left < n && a[left] < a[smallest])
                smallest = left;

            if (right < n && a[right] < a[smallest])
                smallest = right;

            if (smallest == k) break;

            swap(a[k], a[smallest]);
            k = smallest;
        }
    }
}
