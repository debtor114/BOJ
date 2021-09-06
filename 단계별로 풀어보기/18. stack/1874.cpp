#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string ans;
    stack <int> s;

    int k = 1, flag = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        while (1) {
            if (!s.empty() && t == s.top()) {
                s.pop();
                ans.push_back('-');
                break;
            }


            s.push(k++);

            if (k > n+3) {
                flag = 0;
                break;
            }
            ans.push_back('+');
        }
    }

    if (flag == 0) cout << "NO\n";

    else {
        for (int i = 0; i < ans.length(); i++) {
            cout << ans[i] << "\n";
        }
    }

    return 0;


}