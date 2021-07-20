#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    vector <int> v;
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int input;
        cin >> input;
        v.push_back(input);
        sum += input;
    }

    sort(v.begin(), v.end());

    int k, l;
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - v[i] - v[j] == 100) {
                k = i;
                l = j;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i == k || i == l) continue;
        cout << v[i] << endl;
    }

    return 0;
}