#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string input;
        cin >> input;

        stack <char> s;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(') s.push(input[i]);
            else {
                if (!s.empty()) s.pop();
                else {
                    s.push(-1);
                    break;
                }
            }
        }
        if (!s.empty()) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
    return 0;
}