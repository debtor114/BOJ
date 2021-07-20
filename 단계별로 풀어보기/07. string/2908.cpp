#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size() / 2 + 1; i++)
        swap(s[i], s[s.size()- 1- i]);

    for (int i = 0; i < t.size() / 2 + 1 ; i++) 
        swap(t[i], t[t.size()- 1- i]);

    atoi(s.c_str());
    atoi(t.c_str());

    cout << max(s, t) << endl;
    return 0;
       
}