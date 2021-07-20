#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    const string croat[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
    string s, t;
    int count = 0;
    cin >> s;

    for (int i = 0; i < 8; i++) {
        while (s.find(croat[i]) != string::npos) {
            s.replace(s.find(croat[i]), croat[i].length(), "!");
            //cout << s << endl;
        }
    }

    count = s.length();
    cout << count << endl;
    return 0;
}

