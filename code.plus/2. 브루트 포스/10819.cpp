#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

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


    sort(v.begin(), v.end());
    int max_NUM = -1;
    
    do {
        int sum = 0;
        for (int i = 0; i < N-1; i++) {
            sum += abs(v[i] - v[i+1]);
        }

        if (max_NUM < sum) {
            max_NUM = sum;
        }

    } while (next_permutation(v.begin(), v.end()));


    cout << max_NUM << endl;
    return 0;
    
}