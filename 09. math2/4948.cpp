#include <cstdio>
#include <math.h>
#include <memory.h>

using namespace std;

#define MAX 123456

int main() {
    int N = -1;
    bool prime[MAX * 2 + 1];
    
    memset(prime, -1, sizeof(prime));
    
    prime[0] = false;
    prime[1] = false;
    
    for (int i = 2; i <= (int)sqrt(2*MAX+1); i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 2*MAX + 1; j += i) { 
                prime[j] = false;
            }
        }
    }

    while (1) {
        scanf("%d", &N);
        if (N == 0) 
            break;

        int count = 0;
        for (int i = N+1; i <= 2 * N; i++) {
            if (prime[i]) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}