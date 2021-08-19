#include <cstdio>
#include <algorithm>

using namespace std;

int memo[1000001];


int main() {
    int N;
    scanf("%d", &N);

    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;

    for (int i = 4; i <= N; i++) {
        if (i % 2 == 0 && i % 3 == 0) 
            memo[i] = 1 + min( min(memo[i/2], memo[i-1]), memo[i/3] );

        else if (i % 2 == 0)
            memo[i] = 1 + min(memo[i/2], memo[i-1]);

        else if (i % 3 == 0)
            memo[i] = 1 + min(memo[i/3], memo[i-1]);

        else 
            memo[i] = 1 + memo[i-1];

    }

    printf("%d\n", memo[N]);
    return 0;

}