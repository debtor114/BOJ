#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    long long memo[1000001];

    memo[0] = 1;
    memo[1] = 2;

    for (int i = 2; i < 1000000; i++) {
        memo[i] = (memo[i-1]%15746 + memo[i-2]%15746)%15746;
    }

    printf("%lld\n", memo[N-1]);
    return 0;
}