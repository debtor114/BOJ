#include <cstdio>
#include <memory.h>

using namespace std;

int main() {
    bool prime[10001];
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    
    for (int i = 2; i <= 100; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 10000; j += i)
                prime[j] = false;
        }
    }

    int T;
    scanf("%d", &T);
    while (T--) {
        int N, p1, p2;
        scanf("%d", &N);

        for (int i = N/2; i < N; i++) {
            if (prime[i]) {
                p2 = i;
                if (prime[N - p2]) {
                    p1 = N - p2;
                    break;  
                }
            }
        }
        printf("%d %d\n", p1, p2);
    
    }
    return 0;
}