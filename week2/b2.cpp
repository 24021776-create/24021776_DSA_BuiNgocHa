
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head=NULL;

void insert(int x,int k){
    Node *p=new Node{x,NULL};
    if(k==0){
        p->next=head;
        head=p;
        return;
    }
    Node *q=head;
    for(int i=0;i<k-1&&q!=NULL;i++) q=q->next;
    if(q==NULL){
        cout<<"Vi tri khong hop le!\n";
        delete p;
        return;
    }
    p->next=q->next;
    q->next=p;
}
// O(n)

void remove(int k){
    if(head==NULL){
        cout<<"Danh sach rong!\n";
        return;
    }
    if(k==0){
        Node *p=head;
        head=head->next;
        delete p;
        return;
    }
    Node *q=head;
    for(int i=0;i<k-1&&q!=NULL;i++) q=q->next;
    if(q==NULL||q->next==NULL){
        cout<<"Vi tri khong hop le!\n";
        return;
    }
    Node *p=q->next;
    q->next=p->next;
    delete p;
}
// O(n)

void display(){
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
// O(n)

int main(){
    int ch,x,k;
    do{
        cout<<"1. Them\n2. Xoa\n3. Hien thi\n0. Thoat\n";
        cin>>ch;
        if(ch==1){
            cout<<"Nhap gia tri va vi tri: ";
            cin>>x>>k;
            if(k<0) cout<<"Vi tri khong hop le!\n";
            else insert(x,k);
        }
        else if(ch==2){
            cout<<"Nhap vi tri can xoa: ";
            cin>>k;
            if(k<0) cout<<"Vi tri khong hop le!\n";
            else remove(k);
        }
        else if(ch==3) display();
    }while(ch!=0);
    return 0;
}
