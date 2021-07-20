#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    int distribution[10] = { 0 };
    cin >> a >> b >> c;

    string ans = to_string(a * b * c);

    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] == '0') distribution[0]++;
        if (ans[i] == '1') distribution[1]++;
        if (ans[i] == '2') distribution[2]++;
        if (ans[i] == '3') distribution[3]++;
        if (ans[i] == '4') distribution[4]++;
        if (ans[i] == '5') distribution[5]++;
        if (ans[i] == '6') distribution[6]++;
        if (ans[i] == '7') distribution[7]++;
        if (ans[i] == '8') distribution[8]++;
        if (ans[i] == '9') distribution[9]++;
    }

    for (int i = 0; i < 10; i++) {
        cout << distribution[i] << endl;
    }
    return 0;
}