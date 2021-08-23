#include <cstdio>
#include <cmath>

using namespace std;

long long recursive (int a, int b, int c) {

    int n;
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        n = recursive(a, b/2, c);
        return ((n%c)*(n%c))%c;
    }

    else {
        n = recursive(a, (b-1)/2, c);
        return a*((n%c)*(n%c))%c;
    }
}

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    printf("%lld\n", recursive(A, B, C));
    return 0;
}