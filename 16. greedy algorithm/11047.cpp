#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    int arr[10];
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int start = -1;
    for (int i = 0; i < N-1; i++) {
        if (arr[i] <= K && arr[i+1] >= K) {
            start = i;
            break;
        }
    }

    if (start == -1) start = N-1;


    int count = 0;
    while (K != 0) {
        while (arr[start] > K) start--;
        K -= arr[start];
        count++;
    }

    printf("%d\n", count);
    return 0;
}