#include <iostream>

using namespace std;

int width (string s) {
    int result = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') result += 4;
        else if (s[i] == '1') result += 2;
        else result += 3;
    }

    result += n+1;
    return result;

}

int main() {
    string N;
    while (1) {
         cin >> N;
         if (N == "0") break;
         cout << width(N) << "\n";
    }
    return 0;
}