#include <iostream>

using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    N /= 100;
    N *= 100;

    int ans;

    for (int i = 0; i < 100; i++) {
        if ((N+i) % F == 0) {
            ans = i;
            break;
        }
    }

    if (ans / 10 == 0) cout << "0";

    cout << ans << endl;
    return 0;
}