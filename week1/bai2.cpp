#include <iostream>
using namespace std;
void sortArray(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
// Độ phức tạp thời gian: O(N^2), Độ phức tạp bộ nhớ: O(1)
int main(){
    int N;
    cin>>N;
    int a[100];
    for(int i=0;i<N;i++) cin>>a[i];
    sortArray(a,N);
    for(int i=0;i<N;i++) cout<<a[i]<<" ";
    return 0;
}
