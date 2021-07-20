#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s;
    t = s;
    vector < pair <int, char> > key_value;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] > 96 && s[i] < 123)
            s[i] -= 32;
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    for (int i = 0; i < s.size(); i++) 
        key_value.push_back(make_pair(0, s[i]));


    for (int i = 0; i < t.length(); i++) {
        if (t[i] > 96 && t[i] < 123)
            t[i] -= 32;
        
        for (int j = 0; j < key_value.size(); j++) {
            if (key_value[j].second == t[i]) {
                key_value[j].first++;
                break;
            }
        }
    }

    sort(key_value.begin(), key_value.end());
    // for (int i = 0; i < key_value.size(); i++)
    //     cout << key_value[i].first << " " << key_value[i].second << endl; 

    if (key_value[key_value.size()-2].first == key_value[key_value.size()-1].first)
        cout << "?" << endl;

    else 
        cout << key_value[key_value.size()-1].second << endl;
    
    
    return 0;
}