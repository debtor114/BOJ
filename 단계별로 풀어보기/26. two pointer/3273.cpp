#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> v;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int k;
    cin >> k;

    sort(v.begin(), v.end());

    int start = 0, end = N-1, sum = 0, count = 0;
    while (start < end) {
        sum = v[start] + v[end];
        if (sum == k) count++;
        
        if (sum >= k) end--;
        else start++;

    }
    cout << count << endl;
    return 0;
}