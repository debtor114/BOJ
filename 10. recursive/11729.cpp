#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

vector <int> v1, v2, v3;

void hanoi (int N, int src, int dest, int via) {
    if (N == 1) printf("%d %d\n", src, dest);
    else {
        hanoi(N-1, src, via, dest);
        printf("%d %d\n", src, dest);
        hanoi(N-1, via, dest, src);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", (int)pow(2, N)-1);
    hanoi (N, 1, 3, 2);
    return 0;

}