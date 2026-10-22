
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;

void push(int x) {
    Node *p = new Node{x, top};
    top = p;
}
// O(1)

void pop() {
    if (top == NULL) {
        cout << "Stack rong!\n";
        return;
    }
    Node *p = top;
    top = top->next;
    delete p;
}
// O(1)

void display() {
    for (Node *p = top; p != NULL; p = p->next)
        cout << p->data << " ";
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
