#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 1;
    while (N != 1) {
        if (N % 2 == 1) ans++;
        N /= 2;
    }

    cout << ans << endl;
    return 0;
}