#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < 2*N; i++) {
        for (int j = 0; j < N; j++) {       
            if (j % 2 == 0 && i % 2 == 0) printf("*");
            else if (j % 2 == 1 && i % 2 == 0) printf(" ");
            else if (j % 2 == 0 && i % 2 == 1) printf(" ");
            else printf("*");  
        }
        printf("\n");
    }

    return 0;
}