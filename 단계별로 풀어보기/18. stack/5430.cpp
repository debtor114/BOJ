#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>


using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int n;
        cin >> n;
        deque <int> d;

        string array;
        cin >> array;

        for (int i = 0; i < array.size(); i++) {
            if (isdigit(array[i])) {
                int k = 0;
                string num;
                while (1) {
                    if (!isdigit(array[i+k])) {
                        d.push_back(stoi(num));
                        i += k;
                        break;
                    }

                    num.push_back(array[i+k]);
                    k++;
                }
            }
        }

        int flag = 0;
        int error = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') flag = !flag;
            if (s[i] == 'D') {
                if (d.empty()) {
                    cout << "error\n";
                    error = 1;
                    break;
                }

                else {
                    if (flag == 0) d.pop_front();
                    else d.pop_back();                 
                }
            }
        }

        if (!error) {
            if (flag == 0) {
                cout << "[";
                for (int i = 0; i < d.size(); i++) {
                    
                    cout << d[i];
                    if (i != d.size()-1) cout << ",";

                }
                cout << "]\n";
            }

            else {
                cout << "[";
                for (int i = d.size()-1; i >= 0; i--) {
                    
                    cout << d[i];
                    if (i != 0) cout << ",";

                }
                cout << "]\n";
            }      
            
        }
    }

    return 0;
}


