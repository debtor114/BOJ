#include <iostream>
#include <vector>

using namespace std;

string decimalToBinary(int n) {
    string str = ""; 

    while (n != 0) {
        str += (n%2 + '0');
        n /= 2;

    }
    reverse(str.begin(), str.end());
    //cout << str << "\n";
    return str;
}

long long modN (string s, int a) {
    int mod = 1;
    int n = s.length();
    int digit[20];

    digit[0] = 1;
    digit[1] = a % 10;

    for (int i = 2; i < n; i++) {
        mod = digit[i-1] * digit[i-1];
        digit[i] = mod % 10;
    }


    long long sum = 1;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == '1') {
            sum *= digit[n-1-i];
            //cout << digit[i];
        }
    }

    cout << sum << "\n";

    return sum%10;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;

        cout << modN(decimalToBinary(b), a) << "\n";

    }
    return 0;
    
}
