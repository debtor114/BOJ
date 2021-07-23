#include <iostream>

using namespace std;

long long combination (int n, int r) {
    if (r == 0) return 1;
    else return n * combination(n-1, r-1);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int a, b;
        cin >> b >> a;

        long long c = 1;
        for (int i = 1; i <= min(b, (a-b)); i++)
            c *= i;
        
        cout << combination(a, min((a-b), b)) / c << endl;

    }
    return 0;
}