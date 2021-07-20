#include <cstdio>
#include <memory.h>

using namespace std;

int main() {
    bool prime[1000001];
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    
    for (int i = 2; i <= 10000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 1000000; j += i)
                prime[j] = false;
        }
    }

    int N;
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;
        int p1, p2;
        
        for (int i = 2; i < N; i++) {
            if (prime[i] && prime[N-i]) {
                p1 = i;
                p2 = N-i;
                break;
            } 
        }
        printf("%d = %d + %d\n", N, p1, p2);
    
    }
    return 0;
}