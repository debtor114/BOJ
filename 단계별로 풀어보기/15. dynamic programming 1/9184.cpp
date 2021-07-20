#include <cstdio>

using namespace std;

int w[21][21][21];


void memo() {
    w[0][0][0] = 1;
    w[0][0][1] = 1;
    w[0][1][0] = 1;  
    w[1][0][0] = 1;  
    w[0][1][1] = 1;
    w[1][0][1] = 1;
    w[1][1][0] = 1;

    for (int i = 1; i < 21; i++) {
        for (int j = 1; j < 21; j++) {
            for (int k = 1; k < 21; k++) {
                
                if (i < j && j < k) {
                    w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
                }

                else {
                    w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
                }
            }
        }
    }

}

int main() {
    int a, b, c;
    memo();

    // for (int i = 0; i < 21; i++) {
    //     for (int j = 0; j < 21; j++) {
    //         for (int k = 0; k < 21; k++) {
    //             printf("w[%d][%d][%d] = %d\n", i, j, k, w[i][j][k]);
    //         }
    //     }
    // }


    
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == b && b == c & a == -1) break;

    int i, j, k;
    if (a <= 0 || b <= 0 || c <= 0) {
        i = 0;
        j = 0;
        k = 0;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w[i][j][k]);
        continue;
    }

    if (a > 20 || b > 20 || c > 20 ) {
        i = 20;
        j = 20;
        k = 20;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w[i][j][k]);
        continue;
    }

        printf("w(%d, %d, %d) = %d\n", a, b, c, w[a][b][c]);
    }

    return 0;
}