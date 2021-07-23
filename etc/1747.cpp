#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdbool>
#include <cstring>


using namespace std;

#define maxN 7500000

bool prime[maxN];

void seive() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 4; i < maxN; i+= 2)
        prime[i] = false;

    for (int i = 2; i*i <= maxN; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= maxN; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool palindrome (string s) {
  int N = s.length()-1;

  for (int i = 0; i <= N/2; i++) {
    if (s[i] == s[N-i]) continue;
    else return false;
  }
  
  return true;
}

int minPalinAndPrime(int num) {

    for (int i = num; i < maxN; i++) {
        if (prime[i]) {
            if (palindrome(to_string(i))) {
                return i;
                
            }
        }
    }
    return 0;
}


int main() {
    int N;
    scanf("%d", &N);

    seive();
    
    printf("%d\n", minPalinAndPrime(N));
    return 0;


}

