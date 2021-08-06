#include <iostream>

using namespace std;

int main() {
    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;

    int min_m = m;

    int count = 0;
    while (N != 0) {
        if (min_m == m && m+T > M) {
            cout << "-1" << endl;
            return 0;
        } 

        count++;

        if (m+T <= M) {
            m += T;
            N--;
        }

        else {
            m -= R;
            if (min_m > m) m = min_m;
        }
    }

    cout << count << endl;
    return 0;
}