#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    vector <int> v;
    scanf("%d", &N);

    while (N--) {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += (v.size() - i) * v[i];
    }

    printf("%d\n", ans);
    return 0;
}