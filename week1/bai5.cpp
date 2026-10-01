#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    double a[N],sum=0;
    for(int i=0;i<N;i++){
        cin>>a[i];
        sum+=a[i];
    }
    double tb=sum/N;
    for(int i=0;i<N;i++){
        if(a[i]>=tb) cout<<a[i]<<" ";
    }
    return 0;
}
// Độ phức tạp thời gian: O(N), Độ phức tạp bộ nhớ: O(N)
