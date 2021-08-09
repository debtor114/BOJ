#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2, result;
    cin >> s1 >> s2;

    int flag = 0;

    int l1 = s1.length();
    int l2 = s2.length();

    if (l1 > l2) flag = 1;

    for (int i = 0; i < abs(l1-l2); i++) {
        if (flag) s2 = '0' + s2;
        else s1 = '0' + s1;
    }



    int length = s1.length();

    int carry = 0, sum = 0;

    for (int i = 0; i < length; i++) {
        sum = carry + s1[length-1-i]-'0' + s2[length-1-i]-'0';
        
        carry = 0;
        
        if (sum >= 2) carry = 1, sum -= 2;

        result +=  sum + '0';
    }

    if (carry > 0) result += carry+'0';

    reverse(result.begin(), result.end());

    while (result.length() > 1 && result[0] != '1') {
        result = result.substr(1);
    }

    cout << result << endl;
    return 0;

}