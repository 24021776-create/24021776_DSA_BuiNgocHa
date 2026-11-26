#include <iostream>
using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
};

class SymbolTableList {
    Node* head = nullptr;
public:
    void put(string key, int value) {
        for (Node* p = head; p; p = p->next)
            if (p->key == key) { p->value = value; return; }
        head = new Node{key, value, head};   // chèn vào đầu danh sách
    }

    int get(string key) {
        for (Node* p = head; p; p = p->next)
            if (p->key == key) return p->value;
        return -1;
    }

   void remove(string key) {
    Node *p = head, *prev = nullptr;
    while (p) {
        if (p->key == key) {
            if (prev) prev->next = p->next;  // xóa giữa/cuối
            else head = p->next;             // xóa node đầu
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}
    void print() {
        for (Node* p = head; p; p = p->next)
            cout << p->key << ": " << p->value << "\n";
    }
};
