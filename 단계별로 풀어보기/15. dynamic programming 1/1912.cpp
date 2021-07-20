#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[100001];

int main() {
    int N;
    cin >> N;

    vector <int> v;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v.push_back(input);

    }

    d[0] = 0;
    
    int max_value = -9999;
    for (int i = 1; i <= N; i++) {
        d[i] = max(0, d[i-1]) + v[i-1];
        if (max_value < d[i]) max_value = d[i];

    }

    cout << max_value << endl;
    return 0;
    
}