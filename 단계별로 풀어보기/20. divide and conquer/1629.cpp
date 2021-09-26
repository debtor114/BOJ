#include <cstdio>
#include <cmath>

using namespace std;

long long recursive (int a, int b, int c) {

    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 != 0) return a * recursive(a, b-1, c);

    long long half = recursive(a, b/2, c);
    half %= c;
    
    return (half * half) %c;
}

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%lld\n", recursive(A, B, C) % C);
    return 0;
}