#include <iostream>
using namespace std;

class ArrayList {
private:
    int* data;
    int capacity;
    int size;

    // Hàm mở rộng dung lượng gấp đôi khi đầy - O(n)
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    ArrayList(int initCap = 4) : capacity(initCap), size(0) {
        data = new int[capacity];
    }

    ~ArrayList() { delete[] data; }

    // 1. Thêm vào cuối mảng - O(1) trung bình (Amortized O(1))
    void append(int x) {
        if (size == capacity) resize();
        data[size++] = x;
    }

    // 2. Chèn vào vị trí index bất kỳ - O(n)
    void insert(int index, int x) {
        if (index < 0 || index > size) {
            cout << "Vi tri khong hop le!\n";
            return;
        }
        if (size == capacity) resize();
        for (int i = size; i > index; i--) data[i] = data[i - 1]; // Dịch phải
        data[index] = x;
        size++;
    }

    // 3. Xóa phần tử tại vị trí index - O(n)
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Vi tri khong hop le!\n";
            return;
        }
        for (int i = index; i < size - 1; i++) data[i] = data[i + 1]; // Dịch trái
        size--;
    }

    // 4. Truy xuất phần tử theo index - O(1)
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        return data[index];
    }

    // 5. Tìm kiếm giá trị x - O(n)
    int search(int x) {
        for (int i = 0; i < size; i++)
            if (data[i] == x) return i;
        return -1;
    }

    // 6. In toàn bộ danh sách - O(n)
    void display() {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << "\n";
    }
};
