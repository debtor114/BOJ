#include <iostream>

using namespace std;

int factorial(int n) {
    int ret = 1;
    for (int i = 1; i < n+1; i++)
        ret *= i; 
    return ret;
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}