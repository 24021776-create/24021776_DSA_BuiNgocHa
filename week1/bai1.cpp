#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    int a;

    for (int i = 0; i < N; i++) {
        cin >> a;
        sum += a;
    }

    cout << sum << endl;

    return 0;
}
