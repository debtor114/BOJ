#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N, input, total;
    vector <long long> d, p;

    total = 0;
    scanf("%d", &N);

    for (int i = 0; i < N-1; i++) {
        scanf("%d", &input);
        d.push_back(input);
        total += input;
    }

    for (int i = 0; i < N-1; i++) {
        scanf("%d", &input);
        p.push_back(input);
    }

    long long cost = 0;
    long long stack = 0;
    
    int j = 0;
    for (int i = 0; i < N-1; i++) {
        cost += p[j]*d[i];

        if (p[j] >= p[i+1]) j = i+1;

    }


    printf("%lld\n", cost);
    return 0;
    
}