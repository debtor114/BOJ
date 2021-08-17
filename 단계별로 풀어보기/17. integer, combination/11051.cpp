#include <iostream>

using namespace std;

int memo[1001][1001];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        memo[i][0] = 1;
        memo[i][i] = 1;
    }

    memo[1][0] = memo[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            memo[i][j] = (memo[i-1][j-1]%10007 + memo[i-1][j]%10007)%10007;
        }
    }

    cout << memo[N][K] << "\n";
    return 0;
}