#include <cstdio>
#include <vector>
#include <string>

using namespace std;

long long memo[101][10];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i < 10; i++) {
        memo[1][i] = 1;
    }


    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 9) memo[i][j] = memo[i-1][j-1];
            else if (j == 0) memo[i][j] = memo[i-1][j+1];
            else memo[i][j] = (memo[i-1][j-1]% 1000000000 + memo[i-1][j+1]% 1000000000) % 1000000000;
        }
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++)
        ans += memo[N][i];

    printf("%lld\n", ans % 1000000000);
    return 0;

}