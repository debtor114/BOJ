#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;


bool checkMin(string str, int N) {
    bool isConstructor = false;
    int sum = stoi(str);

    for (int i = 0; i < str.length(); i++) {
        sum += str[i] - '0';
    }

    if (sum == N) return true;
    else return false;

}

int main() {
    int ans = 0;
    int N, minimum;
    
    cin >> N;
    minimum = N - 50;

    for (int i = 0; i < 50; i++) {
        if(checkMin(to_string(minimum+i), N)) {
            ans = minimum+i;
            break;
        }
    }
    cout << ans << endl;
    return 0;

}