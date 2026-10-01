#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long gt=1;
    for(int i=1;i<=n;i++) gt*=i;
    cout<<gt;
    return 0;
}
// Độ phức tạp thời gian: O(N), Độ phức tạp bộ nhớ: O(1)
