
#include <iostream>
using namespace std;

const int M = 10;

struct Node {
    int data;
    Node *next;
};

Node *table[M] = {NULL};

int hashFunction(int x) {
    return x % M;
}

void insert(int x) {
    int h = hashFunction(x);

    Node *p = new Node{x, table[h]};
    table[h] = p;
}

void display() {
    for (int i = 0; i < M; i++) {
        cout << i << ": ";
        Node *p = table[i];

        while (p != NULL) {
            cout << p->data << " -> ";
            p = p->next;
        }

        cout << "NULL" << endl;
    }
}

bool search(int x) {
    int h = hashFunction(x);
    Node *p = table[h];

    while (p != NULL) {
        if (p->data == x)
            return true;
        p = p->next;
    }

    return false;
}

int main() {
    int n, a[100];

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i]);
    }

    cout << "\nBang bam:\n";
    display();

    int x;
    cout << "Nhap so can tim: ";
    cin >> x;

    if (search(x))
        cout << "Tim thay";
    else
        cout << "Khong tim thay";

    return 0;
}
