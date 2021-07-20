#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int count = 0;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s, t;
        cin >> s;

        bool flag = true;
        
        for (int j = 0; j < s.length(); j++) {
            
            if (s[j] == s[j+1]) continue;
            
            else {
                if (t.find(s[j]) != string::npos) {
                    flag = false;
                    // cout << s << " is not group" << endl;
                    break;
                }
            }

            if (t.find(s[j]) == string::npos) {
                t.push_back(s[j]);
                // cout << s[j] << " is in" << endl;
            }   
        }
        if (flag) count++;
    
    }

    cout << count << endl;
    return 0;
}