
#include <iostream>
#include <vector>
using namespace std;

vector<int> q;

void enqueue(int x) {
    q.push_back(x);
}
// O(1) trung bình

void dequeue() {
    if (q.empty()) {
        cout << "Queue rong!\n";
        return;
    }
    q.erase(q.begin());
}
// O(n)

void display() {
    for (int x : q)
        cout << x << " ";
    cout << '\n';
}
// O(n)

int main() {
    int n, x;
    cout << "Nhap so phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        enqueue(x);
    }

    display();
    dequeue();
    cout << "Sau khi dequeue: ";
    display();
}
