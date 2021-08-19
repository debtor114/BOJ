#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int N;
    cin >> N;

    queue <int> q;

    while (N--) {
        string s;
        cin >> s;

        if (s == "push") {
            int k;
            cin >> k;

            q.push(k);
        }

        else {
            if (s == "front") {
                if (!q.empty()) cout << q.front() << "\n";
                else cout << "-1\n";
            }

            else if (s == "back") {
                if (!q.empty()) cout << q.back() << "\n";
                else cout << "-1\n";              
            }

            else if (s == "empty") {
                if (!q.empty()) cout << "0\n";
                else cout << "1\n";                   
            }

            else if (s == "size") {
                cout << q.size() << "\n";
            }

            else {
                if (!q.empty()) {
                    cout << q.front() << "\n";
                    q.pop();
                }

                else cout << "-1\n";
            }
        }
    }

    return 0;
}