#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b;
        char waste;
        scanf("%d%c%d", &a, &waste, &b);
        printf("%d\n", a+b);
    }
    return 0;
}