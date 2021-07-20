#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

int dp[101];

int main() {
    int N;
    vector < pair< int, int> > v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        v.push_back(make_pair(n1, n2));

    }

    sort(v.begin(), v.end());

    int max = 0;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[i].second > v[j].second && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;


        if (max < dp[i]) max = dp[i];
    }


    cout << N - max << endl;

    return 0;
}