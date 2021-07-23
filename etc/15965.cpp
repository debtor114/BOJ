#include <cstdio>
#include <vector>

using namespace std;

int prime[7600000];
vector <int> p;

void sieve (int num) {

    prime[0] = 1;
    prime[1] = 1;

    for (int i = 4; i <= num; i += 2) {
        prime[i] = 1;
    }

    for (int i = 2; i*i <= num; i++) {
        if (prime[i] == 0) {
            for (int j = i*i; j <= num; j += i) {
                prime[j] = 1;
            }
        }
    } 
}

int main() {
    int N;
    scanf("%d", &N);

    sieve(15*N);

    for (int i = 2; i <= N*15; i++) {
        if (prime[i] == 0) {
            p.push_back(i);
        }
    }

    printf("%d\n", p[N-1]);


    return 0;
}