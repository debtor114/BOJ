#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    map <char, int> m;
    while (N--) {
        string s;
        cin >> s;

        if (m.find(s[0]) != m.end()) m[s[0]]++;
        else m[s[0]] = 1;
    }

    string ans = "";
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second >= 5) ans.push_back(iter->first);
    }

    sort(ans.begin(), ans.end());

    if (ans.length() == 0) cout << "PREDAJA" << endl;
    else cout << ans << endl;

    return 0;
}