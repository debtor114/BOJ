#include <cstdio>

using namespace std;

int arr[10001];

int main() {

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        arr[temp]++;

    }
    
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < arr[i]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;

}