#include <cstdio>

int main() {
    int T, N;
    scanf("%d", &T);

    long long memo[101];

    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 1;

    for (int i = 3; i < 101; i++) {
        memo[i] = memo[i-2] + memo[i-3];
    }

    while (T--) {
        scanf("%d", &N);
        printf("%lld\n", memo[N-1]);

    }
    
    return 0;
}