// A+B 8번째

#include <stdio.h>

int main() {
    int A[10001], B[10001], T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }

    for (int i = 0; i < T; i++) {
        printf("Case #%d: %d + %d = %d\n", i+1, A[i], B[i], A[i]+B[i]);
    }
    return 0;
}