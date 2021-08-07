#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convertTobinary (int n, int flag) {
    string str = ""; 

    while (n != 0) {
        str += (n%2 + '0');
        n /= 2;

    }

    if (flag) {
        while (str.length() != 3) 
            str += "0";
    }

    reverse(str.begin(), str.end());
    
    return str;

}

int main() {
    string s, ans = "";
    cin >> s;


    for (int i = 0; i < s.length(); i++) {
        int digit = s[i]-'0';
        ans += convertTobinary(digit, i);
    }

    if (s == "0") cout << "0" << endl;
    else cout << ans << endl;
    return 0;
}