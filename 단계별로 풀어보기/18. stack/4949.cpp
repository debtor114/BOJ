#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;

    while (1) {
        // 한줄씩 입력받을 때 getline!
        getline(cin, s);
        if (s[0] == '.') break;

        int flag = 1;
        stack <char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[') st.push(s[i]);
            else if (s[i] == ')') {
                if (st.empty()) {
                    flag = 0;
                    break;
                }

                if (st.top() == '(') st.pop();
                else {
                    flag = 0;
                    break;
                }
            }

            else if (s[i] == ']') {
                if (st.empty()) {
                    flag = 0;
                    break;
                }

                if (st.top() == '[') st.pop();
                else {
                    flag = 0;
                    break;
                }
            }            
        }

        if (!st.empty()) flag = 0;

        if (flag) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}