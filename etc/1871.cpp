#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        string alpha, num;

        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) alpha.push_back(s[i]);
            if (isdigit(s[i])) num.push_back(s[i]);
        }

        int n1 = 0, n2 = 0;

        for (int i = 0; i < 3; i++) {
            n1 += (s[2-i]-65)*pow(26, i);
        }

        n2 = stoi(num);

        if (abs(n1-n2) <= 100) cout << "nice" << "\n";
        else cout << "not nice" << "\n";
    }

    return 0;

}