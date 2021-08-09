#include <iostream>
#include <string>
#include <cstdbool>

using namespace std;

bool isPalindrome (string s) {
    int N = s.length();
    for (int i = 0; i < N/2; i++) {
        if (s[i] == s[N-1-i]) continue;
        else return false;
    }

    return true;
}

int main() {
    string str;
    while (1) {
        cin >> str;
        if (str =="0") break;

        if (isPalindrome(str)) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
