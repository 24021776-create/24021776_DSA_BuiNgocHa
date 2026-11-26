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
    // Thêm mới hoặc cập nhật giá trị
    void put(string key, int value) {
        for (Node* p = head; p; p = p->next)
            if (p->key == key) { p->value = value; return; }
        head = new Node{key, value, head};   // chèn vào đầu danh sách
    }

    // Tìm giá trị theo key, không có trả về -1
    int get(string key) {
        for (Node* p = head; p; p = p->next)
            if (p->key == key) return p->value;
        return -1;
    }

    // Xóa key
    void remove(string key) {
        Node **pp = &head;
        while (*pp) {
            if ((*pp)->key == key) {
                Node* del = *pp;
                *pp = del->next;
                delete del;
                return;
            }
            pp = &(*pp)->next;
        }
    }

    void print() {
        for (Node* p = head; p; p = p->next)
            cout << p->key << ": " << p->value << "\n";
    }
};
