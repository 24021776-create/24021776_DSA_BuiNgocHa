#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node *p = new Node{x, NULL};

    if (rear == NULL)
        front = rear = p;
    else {
        rear->next = p;
        rear = p;
    }
}
// O(1)

void dequeue() {
    if (front == NULL) {
        cout << "Queue rong!\n";
        return;
    }

    Node *p = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete p;
}
// O(1)

void display() {
    for (Node *p = front; p != NULL; p = p->next)
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
        enqueue(x);
    }

    display();

    dequeue();

    cout << "Sau khi dequeue: ";
    display();

    return 0;
}
