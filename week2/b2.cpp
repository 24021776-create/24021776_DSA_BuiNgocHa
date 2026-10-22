#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
};

class SinglyLinkedList {
private:
    SNode* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // 1. Chèn vào đầu danh sách - O(1)
    void insertHead(int x) {
        SNode* p = new SNode{x, head};
        head = p;
    }

    // 2. Chèn vào cuối danh sách - O(n) (hoặc O(1) nếu duy trì con trỏ tail)
    void insertTail(int x) {
        SNode* p = new SNode{x, nullptr};
        if (head == nullptr) {
            head = p;
            return;
        }
        SNode* curr = head;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = p;
    }

    // 3. Xóa phần tử ở đầu danh sách - O(1)
    void deleteHead() {
        if (head == nullptr) return;
        SNode* p = head;
        head = head->next;
        delete p;
    }

    // 4. Xóa phần tử đầu tiên có giá trị bằng x - O(n)
    void deleteValue(int x) {
        if (head == nullptr) return;
        if (head->data == x) {
            deleteHead();
            return;
        }
        SNode* curr = head;
        while (curr->next != nullptr && curr->next->data != x)
            curr = curr->next;

        if (curr->next != nullptr) {
            SNode* p = curr->next;
            curr->next = p->next;
            delete p;
        }
    }

    // 5. Tìm kiếm phần tử x - O(n)
    bool search(int x) {
        for (SNode* p = head; p != nullptr; p = p->next)
            if (p->data == x) return true;
        return false;
    }

    // 6. In danh sách - O(n)
    void display() {
        for (SNode* p = head; p != nullptr; p = p->next)
            cout << p->data << " ";
        cout << "\n";
    }

    ~SinglyLinkedList() {
        while (head != nullptr) deleteHead();
    }
};
