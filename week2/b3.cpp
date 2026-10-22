#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // 1. Chèn vào đầu danh sách - O(1)
    void insertHead(int x) {
        DNode* p = new DNode{x, nullptr, head};
        if (head == nullptr) {
            head = tail = p;
        } else {
            head->prev = p;
            head = p;
        }
    }

    // 2. Chèn vào cuối danh sách - O(1) (Nhờ có con trỏ tail)
    void insertTail(int x) {
        DNode* p = new DNode{x, tail, nullptr};
        if (tail == nullptr) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    // 3. Xóa ở đầu danh sách - O(1)
    void deleteHead() {
        if (head == nullptr) return;
        DNode* p = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr; // Danh sách trở thành rỗng
        delete p;
    }

    // 4. Xóa ở cuối danh sách - O(1)
    void deleteTail() {
        if (tail == nullptr) return;
        DNode* p = tail;
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        else head = nullptr; // Danh sách trở thành rỗng
        delete p;
    }

    // 5. Xóa một Node biết trước địa chỉ con trỏ p - O(1)
    void deleteNode(DNode* p) {
        if (p == nullptr) return;
        if (p == head) { deleteHead(); return; }
        if (p == tail) { deleteTail(); return; }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }

    // 6. In từ đầu đến cuối (Forward) - O(n)
    void displayForward() {
        for (DNode* p = head; p != nullptr; p = p->next)
            cout << p->data << " ";
        cout << "\n";
    }

    // 7. In ngược từ cuối lên đầu (Backward) - O(n)
    void displayBackward() {
        for (DNode* p = tail; p != nullptr; p = p->prev)
            cout << p->data << " ";
        cout << "\n";
    }

    ~DoublyLinkedList() {
        while (head != nullptr) deleteHead();
    }
};
