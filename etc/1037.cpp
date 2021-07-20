#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector <int> factor;

    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        factor.push_back(temp);
    }

    sort(factor.begin(), factor.end());

    long long ans = factor.front() * factor.back();
    printf("%lld\n", ans);
    return 0;
}