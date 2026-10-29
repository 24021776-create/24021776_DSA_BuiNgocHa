
#include <iostream>
using namespace std;

const int M = 10;

struct Node {
    int data;
    Node *next;
};

Node *table[M] = {NULL};

int hashFunction(int x) {
    return ((x % M) + M) % M;
}

void insert(int x) {
    int h = hashFunction(x);
    Node *p = new Node{x, table[h]};
    table[h] = p;
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

void removeElement(int x) {
    int h = hashFunction(x);
    Node *p = table[h];
    Node *prev = NULL;

    while (p != NULL) {
        if (p->data == x) {
            if (prev == NULL)
                table[h] = p->next;
            else
                prev->next = p->next;

            delete p;
            cout << "Da xoa " << x << endl;
            return;
        }

        prev = p;
        p = p->next;
    }

    cout << "Khong tim thay " << x << endl;
}

void display() {
    for (int i = 0; i < M; i++) {
        cout << i << ": ";
        Node *p = table[i];

        while (p != NULL) {
            cout << p->data << " -> ";
            p = p->next;
        }

        cout << "NULL\n";
    }
}

int main() {
    int n, x, chon;

    cout << "Nhap so phan tu: ";
    cin >> n;

    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }

    do {
        cout << "\n1. Them\n";
        cout << "2. Tim kiem\n";
        cout << "3. Xoa\n";
        cout << "4. In bang bam\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        if (chon == 1) {
            cout << "Nhap so can them: ";
            cin >> x;
            insert(x);
        }
        else if (chon == 2) {
            cout << "Nhap so can tim: ";
            cin >> x;

            if (search(x))
                cout << "Tim thay\n";
            else
                cout << "Khong tim thay\n";
        }
        else if (chon == 3) {
            cout << "Nhap so can xoa: ";
            cin >> x;
            removeElement(x);
        }
        else if (chon == 4) {
            display();
        }

    } while (chon != 0);

    return 0;
}
