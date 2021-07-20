// 예외처리 덜함

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int count = 1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 32)
            count++;

    }
    cout << count << endl;
    return 0;

}