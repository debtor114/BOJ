#include <iostream>

using namespace std;

#define ll long long

int main () {
    ll a, b, c;
    ll x = 0;

    cin >> a >> b >> c;

    if (c-b <= 0) {
        x = -1;
        cout << x << endl;
        return 0;
    }

    else {
        while (a / (c - b) >= x) 
            x++;
        
        cout << x << endl;
    }
    return 0;
    
}