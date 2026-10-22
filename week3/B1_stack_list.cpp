
#include <iostream>
#include <vector>
using namespace std;

vector<int> s;

void push(int x) {
    s.push_back(x);
}
// O(1) trung bình

void pop() {
    if (s.empty()) {
        cout << "Stack rong!\n";
        return;
    }
    s.pop_back();
}
// O(1)

void display() {
    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i] << " ";
    cout << '\n';
}
// O(n)

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
