#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 5 != 0) continue;
        int prime = 2;
        int n = i;
        while (n > 1) {
            if (n % prime == 0) {
                n /= prime;
                if (prime == 5) count++;
            }
            
            else prime++; 
        }
    }
    
    printf("%d\n", count);
    return 0;
}