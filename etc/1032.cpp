#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
 
int main() {
    int N;
    cin >> N;

    string s1;
    cin >> s1;
    int length = s1.length();

    for (int i = 1; i < N; i++) {
        string s2;
        cin >> s2;
        string temp;
        for (int j = 0; j < s1.length(); j++) {
            if (s1[j] == s2[j]) temp.push_back(s1[j]);
            else temp.push_back('?');
        }

        s1 = temp;
    }

    cout << s1 << "\n";
    return 0;
    
}