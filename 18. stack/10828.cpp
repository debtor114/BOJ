#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int N;
    stack <int> s;

    scanf("%d", &N);

    while(N--) {
        string operation;
        cin >> operation;
        
        if (operation == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (operation == "pop") {
            if (!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            }
            else cout << "-1" << "\n";
        }
        else if (operation == "size") cout << s.size() << "\n";
        else if (operation == "empty") cout << s.empty() << "\n";
        else {
            if (!s.empty()) cout << s.top() << "\n";
            else cout << "-1" << "\n";
        }
    }
    return 0;
}
