#include <cstdio>

int main() {
    int N;
    int xor_sum = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        xor_sum = xor_sum^input;
    }

    printf("%d\n", xor_sum);
    return 0;
        


}