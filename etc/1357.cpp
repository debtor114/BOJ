#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string ans = to_string(stoi(s1) + stoi(s2));
    reverse(ans.begin(), ans.end());

    cout << stoi(ans) << endl;

    return 0;
}