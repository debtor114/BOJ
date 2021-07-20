#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, ans;
    int arr[1000][3], memo[1000][3];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    memo[0][0] = arr[0][0];
    memo[0][1] = arr[0][1];
    memo[0][2] = arr[0][2];

    for (int i = 1; i < N; i++) {
        memo[i][0] = min(memo[i-1][1], memo[i-1][2]) + arr[i][0];
        memo[i][1] = min(memo[i-1][0], memo[i-1][2]) + arr[i][1];
        memo[i][2] = min(memo[i-1][0], memo[i-1][1]) + arr[i][2];
    }

    ans = min(memo[N-1][0], min(memo[N-1][1], memo[N-1][2]));
    printf("%d\n", ans);
    return 0;
}