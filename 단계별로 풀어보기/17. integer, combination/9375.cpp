#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        map <string, int> m;
        cin >> N;
        for (int i = 0; i < N; i++) {
            string a, b;
            cin >> a >> b;
            if (m.find(b) != m.end()) m[b]++;
            else m[b] = 1;
        }

        int sum = 1;
        for (auto iter : m) {
            sum *= (iter.second)+1;
        }

        cout << sum-1 << "\n";
    }
    return 0;
}