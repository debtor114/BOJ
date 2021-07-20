#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int memo[300][2];

int main() {
    int N;
    scanf("%d", &N);

    vector <int> v;
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    memo[0][0] = 0;
    memo[0][1] = 0;
    memo[1][0] = v[0];
    memo[1][1] = v[0];

    for (int i = 2; i <= N; i++) {
        memo[i][0] = max(memo[i-2][0], memo[i-1][1]) + v[i-1];
        memo[i][1] = max(memo[i-2][1], memo[i-2][0]) + v[i-1]; 
    }

    printf("%d\n", max(memo[N][0], memo[N][1]));
    return 0;

}