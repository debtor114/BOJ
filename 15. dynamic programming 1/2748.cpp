#include <cstdio>

int main() {
    int N;
    long long memo[91] = { 0, };
    scanf("%d", &N);

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= N; i++)
        memo[i] = memo[i-1] + memo[i-2];


    printf("%lld\n", memo[N]);
    return 0;
}