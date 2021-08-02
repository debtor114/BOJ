#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int prime[1000001];
vector <int> primes;


bool check (string s, int k) {
    int sum = 0;
    int length = s.length();

    for (int i = 0; i < length; i++) {
        sum = (sum*10+(s[i]-'0'))%k;
    }

    if (sum == 0) return true;
    else return false;

}

void seive (int k) {

    prime[0] = prime[1] = 1;

    for (int i = 2; i < k; i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (int j = 2*i; j <= k; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int main() {
    string P;
    int k;

    cin >> P >> k;

    seive(k);

    for (int i = 0; i < primes.size(); i++) {
        if (check(P, primes[i])) {
            cout << "BAD " << primes[i] << endl; 
            return 0;
        }
    }

    cout << "GOOD" << endl;
    return 0;
}