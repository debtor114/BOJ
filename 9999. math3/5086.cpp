#include <cstdio>

int main() {
    int a, b;
    while (true) {
        scanf("%d %d", &a, &b);
        if (a == 0 || b == 0) break;

        int result1, result2;

        result1 = a%b;
        result2 = b%a;

        if (result2 == 0) printf("factor\n");
        else if (result1 == 0) printf("multiple\n");
        else printf("neither\n");
    }
    return 0;
}