#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int color(string s) {
    if (s == "black") return 0;
    else if (s == "brown") return 1;
    else if (s == "red") return 2;
    else if (s == "orange") return 3;
    else if (s == "yellow") return 4;
    else if (s == "green") return 5;
    else if (s == "blue") return 6;
    else if (s == "violet") return 7;
    else if (s == "grey") return 8;
    
    return 9;
}

int main() {
    string c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    long long ans = (color(c1) * 10 + color(c2)) * pow(10, color(c3));
    cout << ans << endl;
    return 0;

}