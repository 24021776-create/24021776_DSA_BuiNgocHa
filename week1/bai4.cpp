#include <iostream>
using namespace std;
void rutGon(int &a,int &b){
    int x=a,y=b;
    while(y!=0){
        int r=x%y;
        x=y;
        y=r;
    }
    a/=x;
    b/=x;
    if(b<0){
        a=-a;
        b=-b;
    }
}
// Độ phức tạp thời gian: O(log(min(|a|,|b|))), Độ phức tạp bộ nhớ: O(1)
int main(){
    int a,b;
    cin>>a>>b;
    rutGon(a,b);
    cout<<a<<"/"<<b;
    return 0;
}
