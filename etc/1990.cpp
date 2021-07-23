#include <cstdio>
#include <string>
#include <cstdbool>
#include <cmath>

#define MAX 10000001

using namespace std;
int a, b;
bool seive[MAX];


bool palindrome (string s) {
  int N = s.length()-1;

  for (int i = 0; i <= N/2; i++) {
    if (s[i] == s[N-i]) continue;
    else return false;
  }
  
  return true;
}

bool isPrime (int N) {
  for (int i = 2; i*i <= N; i++) {
    if (N % i == 0) return false;
  }
  
  return true;
}

int main() {
    scanf("%d %d", &a, &b);
    if (b > MAX - 1)  b = MAX - 1;
    
    for (int i = 2; i < MAX; i++)
        if (palindrome(to_string(i))) seive[i] = true;
        
    
    for (int i = a; i <= b; i++)
        if (seive[i])
            if (isPrime(i)) printf("%d\n", i);

    printf("-1");
    return 0;
}