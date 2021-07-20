#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(const pair <int, int> &p1, const pair <int, int> &p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}


int main() {
    int N;
    vector < pair <int, int> > v;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), comp);
    
    for (int i = 0; i < N; i++) 
        printf("%d %d\n", v[i].first, v[i].second);

    return 0;
}