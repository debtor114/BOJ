#include <cstdio>

using namespace std;

int factorial(int N) {
  if (N == 1)
    return 1;

  else
    return N * factorial(N-1);
}

int main() {
  int N, ans;
  scanf("%d", &N);
  ans = factorial(N);
  printf("%d\n", ans);
  return 0;
}
