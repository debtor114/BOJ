#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int T, N;
    cin >> T;

    while(T--) {
        cin >> N >> s;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < N; j++) {
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}