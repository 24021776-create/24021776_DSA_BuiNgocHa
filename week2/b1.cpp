
#include <iostream>
using namespace std;

int a[1000], n=0;

void insert(int x,int k){
    for(int i=n;i>k;i--) a[i]=a[i-1];
    a[k]=x;
    n++;
}
// O(n)

void remove(int k){
    for(int i=k;i<n-1;i++) a[i]=a[i+1];
    n--;
}
// O(n)

void display(){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
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
            if(k<0||k>n||n==1000) cout<<"Vi tri khong hop le!\n";
            else insert(x,k);
        }
        else if(ch==2){
            cout<<"Nhap vi tri can xoa: ";
            cin>>k;
            if(k<0||k>=n) cout<<"Vi tri khong hop le!\n";
            else remove(k);
        }
        else if(ch==3) display();
    }while(ch!=0);
    return 0;
}
