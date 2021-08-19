#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int memo[1000001];
int trace[1000001];


int main() {
    int N;
    scanf("%d", &N);

    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;

    trace[1] = 1;
    trace[2] = 1;
    trace[3] = 1;


    for (int i = 4; i <= N; i++) {
        
        if (i % 2 == 0 && i % 3 == 0) {
            if (memo[i/2] > memo[i-1]) {
                if (memo[i-1] > memo[i/3]) trace[i] = i/3;
                else trace[i] = i-1;
            }

            else {
                if (memo[i/2] > memo[i/3]) trace[i] = i/3;
                else trace[i] = i/2;
            }


            memo[i] = 1 + min( min(memo[i/2], memo[i-1]), memo[i/3] );
        }

        else if (i % 2 == 0) {
            if (memo[i/2] > memo[i-1]) trace[i] = i-1;
            else trace[i] = i/2;
            memo[i] = 1 + min(memo[i/2], memo[i-1]);

        }
            

        else if (i % 3 == 0) {
            if (memo[i/3] > memo[i-1]) trace[i] = i-1;
            else trace[i] = i/3;            
            memo[i] = 1 + min(memo[i/3], memo[i-1]);
        }


        else {
            trace[i] = i-1;
            memo[i] = 1 + memo[i-1];

        }

    }

    printf("%d\n", memo[N]);

    while (N != 1) {
        printf("%d ", N);
        N = trace[N];
    }

    printf("1\n");

    return 0;

}