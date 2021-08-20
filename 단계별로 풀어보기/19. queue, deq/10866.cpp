#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);    

    int N;
    cin >> N;
    deque <int> dq;
    while (N--) {
        string op;
        cin >> op;
        if (op == "push_back" || op == "push_front") {
            int k;
            cin >> k;
            
            if (op == "push_back") dq.push_back(k);
            else dq.push_front(k);
        }

        else {
            if (op == "front") {
                if (!dq.empty()) cout << dq.front() << "\n";
                else cout << "-1\n";
            }

            else if (op == "back") {
                if (!dq.empty()) cout << dq.back() << "\n";
                else cout << "-1\n";
            }

            else if (op == "size") cout << dq.size() << "\n";
            else if (op == "empty") {
                if (dq.empty()) cout << "1\n";
                else cout << "0\n";
            }

            else if (op == "pop_front") {
                if (!dq.empty()) {
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
                else cout << "-1\n";                
            }

            else if (op == "pop_back") {
                if (!dq.empty()) {
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
                else cout << "-1\n";                    
            }
        }
    }

    return 0;
}