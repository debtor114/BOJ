#include <cstdio>

using namespace std;

int w[21][21][21];


int main() {
    int a, b, c;

    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                if (i <= 0 || j <= 0 || k <= 0) w[i][j][k] = 1;
            }
        }
    }

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            for (int k = 1; k <= 20; k++) {

                
                
                if (i < j && j < k) {
                    w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
                }

                else {
                    w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
                }
            }
        }
    }

    
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == b && b == c && a == -1) break;

        if (a <= 0 || b <= 0 || c <= 0) {
            printf("w(%d, %d, %d) = %d\n", a, b, c, w[0][0][0]);
            continue;
        }

        else if (a > 20 || b > 20 || c > 20 ) {
            printf("w(%d, %d, %d) = %d\n", a, b, c, w[20][20][20]);
            continue;
        }

        else {
            printf("w(%d, %d, %d) = %d\n", a, b, c, w[a][b][c]);
        }
    }

    return 0;
}