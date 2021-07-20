#include <iostream>
#include <string>

using namespace std;

int main() {

    string s;
    int arr[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        int j = s[i]-97;
        if (arr[j] != -1)
            continue;

        arr[j] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }
        cout << endl;

    
    return 0;
}