#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = i; j < N; j++)
            printf(" ");

        for (int j = 0; j < 2*i-1; j++)
            printf("*");

        // for (int j = i; j < N; j++)
        //     printf(" ");

        printf("\n");
    }

    return 0;
}