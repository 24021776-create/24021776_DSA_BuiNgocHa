#include <iostream>
using namespace std;

int tong(int a[][100],int n,int m){
    int sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            sum+=a[i][j];
    return sum;
}

void xoaDong(int a[][100],int &n,int m,int i){
    for(int r=i;r<n-1;r++)
        for(int c=0;c<m;c++)
            a[r][c]=a[r+1][c];
    n--;
}

// Độ phức tạp thời gian: O(N*M), Độ phức tạp bộ nhớ: O(1)

int main(){
    int N,M;
    cin>>N>>M;
    int a[100][100];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>a[i][j];

    cout<<tong(a,N,M)<<endl;

    int i;
    cin>>i;
    xoaDong(a,N,M,i);

    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++)
            cout<<a[r][c]<<" ";
        cout<<endl;
    }
    return 0;
}
