#include <queue>
#include <cstdio>

using namespace std;

priority_queue <int> pq;

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int input;
        scanf("%d", &input);

        if (input == 0) {
            if (pq.empty()) printf("0\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }

        else {
            pq.push(input);
        }
        
    }

    return 0;
}