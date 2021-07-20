#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int N;
    map <string, int> m;
    vector <string> str;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        

        if (m.find(s) == m.end()) {
            m.insert(make_pair(s, 1));
            str.push_back(s);
        }
        else m[s]++;

    }


    sort(str.begin(), str.end());

    int max = -1;
    string ans = "";
    for (int i = 0; i < str.size(); i++) {
        if (m[str[i]] > max) {
            max = m[str[i]];
            ans = str[i];
        }
    }

    cout << ans << endl;

    return 0;
}