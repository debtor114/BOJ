#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

int main() {
    char arr[10];
    string num;
    cin >> num;

    for (int i = 0; i < num.length(); i++) {
        arr[i] = num[i];
    }
    sort(arr, arr+num.length(), greater<char>());

    for (int i = 0; i < num.length(); i++)
        cout << arr[i];

    cout << endl;
    return 0;
}