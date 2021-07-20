#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v, list;

int visit[10];

int N, M;

void permutation_dup(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
            printf("%d ", list[i]);

        printf("\n");

        return;
    }

    for (int i = 0; i < N; i++) {
            list.push_back(v[i]);
            permutation_dup(depth+1);
            list.pop_back();
    }

}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    permutation_dup(0);

    return 0;
}