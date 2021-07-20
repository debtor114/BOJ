#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < 2*N-1; i++) {
        if (i % 2 == 1) continue;

        for (int j = i/2; j < i; j++) printf(" ");
        for (int j = i; j < 2*N - 1; j++) printf("*");
        printf("\n");
    }

    for (int i = 1; i < 2*N-1; i++) {
        if (i % 2 == 0) continue;

        for (int j = 0; j < N - 2- i/2; j++) printf(" ");
        for (int j = 0; j < i+2; j++) printf("*");
        printf("\n");
    }

    return 0;
}