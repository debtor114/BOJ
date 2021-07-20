#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) { 
        for (int j = N-i; j < N; j++){
            printf(" ");
        }
        for (int j = 2*i; j < 2*N-1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}