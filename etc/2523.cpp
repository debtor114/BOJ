#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i+1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 0 ; i < N-1; i++) {
        for (int j = N-i; j > 1; j--) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}