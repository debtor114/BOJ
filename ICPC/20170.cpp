#include <iostream>
#include <vector>

using namespace std;

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    vector <int> d1, d2;

    for (int i = 0; i < 6; i++) {
        int input;
        cin >> input;
        d1.push_back(input);
    }

    for (int i = 0; i < 6; i++) {
        int input;
        cin >> input;
        d2.push_back(input);
    }

    int win = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (d1[i] > d2[j]) win++;
        }
    }

    int GCD = gcd(win, 36);
    
    cout << win/GCD << "/" << 36/GCD << "\n";
    return 0;
}