#include <cstdio>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int matrics[501][2];
    int d[1002];
    int M[501][501];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &matrics[i][0], &matrics[i][1]);
    }

    d[0] = matrics[0][0];
    for (int i = 0; i < N; i++) d[i+1] = matrics[i][1];
    for (int i = 1; i <= N; i++) M[i][i] = 0;
    for (int r = 2; r <= N; r++) { 
        for (int i = 1; i <= N-r+1; i++) {
            int j = i+r-1;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) { 
                if (M[i][j] > M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j]) {
                    M[i][j] = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
                }    
            }
        }
    }

    printf("%d\n", M[1][N]);
    return 0;
}