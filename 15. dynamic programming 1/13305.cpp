#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector <int> d, p;

    int sum = 0;
    int cost = 0;

    for (int i = 0; i < N-1; i++) {
        int temp;
        scanf("%d", &temp);
        d.push_back(temp);
        sum += temp;
    }

    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        p.push_back(temp);

    }

    for (int i = 0; sum <= 0; i++) {
        if (p[i] > p[i+1]) {
            cost += p[i]*d[i];
            sum -= d[i];
        }

        else {
            
        }
    }

}