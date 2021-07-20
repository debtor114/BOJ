#include <cstdio>
#include <cmath>
#include <memory.h>

using namespace std;

int main() {
    int M, N;
    bool prime[1000001];
    scanf("%d %d", &M, &N);

    memset(prime, 1, sizeof(prime));

    // 에라토스테네스의 체
    prime[0] = false;
    prime[1] = false;
    
    for (int i = 2; i <= 1000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (prime[i]) 
            printf("%d\n", i);
    }
   
    return 0;
}
