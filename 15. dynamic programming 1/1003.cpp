#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int T, n;
    vector <pair <int, int> > v;
    vector <int> ans;

    scanf("%d", &T);

    // base case
    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(0, 1));

    // n-case
    for (int i = 2; i <= 40; i++)
        v.push_back(make_pair(v[i-1].first + v[i-2].first, v[i-1].second + v[i-2].second));


    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        ans.push_back(n);
    }

    for (int i = 0; i < T; i++) 
        printf("%d %d\n", v[ans[i]].first, v[ans[i]].second);

    return 0;

}