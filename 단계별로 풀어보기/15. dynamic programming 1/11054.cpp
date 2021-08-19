#include <iostream>
#include <vector>

using namespace std;

int memo[1000];

int main() {
    int N;
    cin >> N;

    vector <int> v;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int max = 0;

    for (int i = 0; i < N; i++) {
        memo[i] = 1;

        for (int j = 0; j < i; j++) {
            if (v[i] > v[j] && memo[j] + 1 > memo[i]) memo[i] = memo[j] + 1;
        }

        if (max < memo[i]) max = memo[i];
    }


}