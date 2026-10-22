#include <iostream>
#include <list> 
using namespace std;

list<int> s;

void push(int x) {
    s.push_front(x); // Thêm vào đầu list - O(1)
}

void pop() {
    if (s.empty()) {
        cout << "Stack rong!\n";
        return;
    }
    s.pop_front(); // Xóa ở đầu list - O(1)
}

void display() {
    for (int x : s)
        cout << x << " ";
    cout << '\n';
} // O(n)

int main() {
    int n, x;
    cout << "Nhap so phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        push(x);
    }

    display();
    pop();
    cout << "Sau khi pop: ";
    display();
}
