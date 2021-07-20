#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {  
        string s;
        cin >> s;
        
        stack <char> s1, s2;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') s1.push(s[i]);
            else if (s[i] == '[') s2.push(s[i]);
            else if (s[i] == ')') {
                if (!s1.empty()) s1.pop();
                else {
                    s1.push(-1);
                    break;
                }
            }

            else if (s[i] == ']') {
                if (!s2.empty()) s2.pop();
                else {
                    s2.push(-1);
                    break;
                }            
            }

            else continue;
        }
        if (s1.empty() && s2.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";

        return 0;
    }    
}