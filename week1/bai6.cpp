#include <iostream>
using namespace std;

void xoa(int a[],int &n,int k){
    for(int i=k;i<n-1;i++) a[i]=a[i+1];
    n--;
}

void chen(int a[],int &n,int y,int m){
    for(int i=n;i>m;i--) a[i]=a[i-1];
    a[m]=y;
    n++;
}

// Độ phức tạp thời gian: O(N), Độ phức tạp bộ nhớ: O(1)

int main(){
    int N;
    cin>>N;
    int a[1000];
    for(int i=0;i<N;i++) cin>>a[i];

    int k;
    cin>>k;
    xoa(a,N,k);

    int y,m;
    cin>>y>>m;
    chen(a,N,y,m);

    for(int i=0;i<N;i++) cout<<a[i]<<" ";
    return 0;
}
