#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, arr[1001], memo[1001];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++) {
        memo[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && memo[i] == memo[j])
                memo[i] = memo[j]+1;  
        }
    }

    printf("%d\n", *max_element(memo, memo+N));
    return 0;
}