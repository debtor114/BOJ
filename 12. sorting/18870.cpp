#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    map <int, int> m;
    vector <int> v1, v2;

    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        v1.push_back(temp);
    }

    v2 = v1;

    sort(v1.begin(), v1.end());

    int ord = 0;
    m.insert(make_pair(v1[0], 0));

    for (int i  = 1; i < N; i++) {
        if (v1[i] != v1[i-1]) ord++;
        m.insert(make_pair(v1[i], ord));
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", m[v2[i]]);
    }

    printf("\n");

    return 0;
}