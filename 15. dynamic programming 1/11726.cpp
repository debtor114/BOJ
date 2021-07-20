#include <cstdio>

using namespace std;

int main() {
    int N;
    long long memo[1001];
    scanf("%d", &N);

    memo[0] = 1;
    memo[1] = 2; 
    for (int i = 2; i < N; i++) 
        memo[i] = (memo[i-1] + memo[i-2])%10007;
    
    printf("%lld\n", memo[N-1]);
    return 0;
}