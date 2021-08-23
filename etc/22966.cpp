#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    char prob[5][10];

    for (int i = 0; i < N; i++) {
        int k;
        scanf("%s %d", prob[i], &k);
        strcmp(prob[k], prob[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (prob[i] != NULL) {
            printf("%s\n", prob[i]);
            break;
        }
    }
}