#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comp (const pair <int, int> &p1, const pair <int, int> &p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    int N;
    vector < pair <int, int> > v;

    scanf("%d", &N);
    while (N--) {
        int start, end;
        scanf("%d %d", &start, &end);
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), comp);

    int time = v[0].second;
    int count = 1;
    
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first < time) continue;
        
        time = v[i].second;
        count++;
    }

    printf("%d\n", count);
    return 0;
}