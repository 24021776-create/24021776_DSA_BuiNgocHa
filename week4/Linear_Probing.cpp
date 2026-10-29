
#include <iostream>
using namespace std;

const int M = 10;

int table[M];
int state[M] = {0};

int hashFunction(int x) {
    return ((x % M) + M) % M;
}

void insert(int x) {
    int h = hashFunction(x);

    for (int i = 0; i < M; i++) {
        int j = (h + i) % M;

        if (state[j] == 1 && table[j] == x) {
            cout << "Phan tu da ton tai\n";
            return;
        }
    }

    for (int i = 0; i < M; i++) {
        int j = (h + i) % M;

        if (state[j] != 1) {
            table[j] = x;
            state[j] = 1;
            return;
        }
    }

    cout << "Bang bam da day!\n";
}

bool search(int x) {
    int h = hashFunction(x);

    for (int i = 0; i < M; i++) {
        int j = (h + i) % M;

        if (state[j] == 0)
            return false;

        if (state[j] == 1 && table[j] == x)
            return true;
    }

    return false;
}

void removeElement(int x) {
    int h = hashFunction(x);

    for (int i = 0; i < M; i++) {
        int j = (h + i) % M;

        if (state[j] == 0) {
            cout << "Khong tim thay " << x << endl;
            return;
        }

        if (state[j] == 1 && table[j] == x) {
            state[j] = 2;
            cout << "Da xoa " << x << endl;
            return;
        }
    }

    cout << "Khong tim thay " << x << endl;
}

void display() {
    for (int i = 0; i < M; i++) {
        cout << i << ": ";

        if (state[i] == 1)
            cout << table[i];
        else if (state[i] == 2)
            cout << "DELETED";
        else
            cout << "EMPTY";

        cout << endl;
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
