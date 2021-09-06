#include <iostream>
#include <string>

using namespace std;

int prime[10001];

void seive() {
    for (int i = 2; i <= 10000; i++) {
        if (prime[i] == 0) {
            for (int j = 2*i; j <= 10000; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;

    seive();

    int sum = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') sum += s[i]-96;
        if (s[i] >= 'A' && s[i] <= 'Z') sum += s[i]-38;
    }

    if (prime[sum]) cout << "It is not a prime word." << "\n";
    else cout << "It is a prime word." << "\n";

    return 0;

}