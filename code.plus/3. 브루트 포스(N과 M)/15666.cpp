#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v, list;

int visit[10];

int N, M;

void combination (int depth, int index) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
            printf("%d ", list[i]);

        printf("\n");

        return;
    }

    int prev_num = -1;

    for (int i = index; i < N; i++) {

        if (prev_num != v[i]) {
            list.push_back(v[i]);
            prev_num = v[i];
            combination(depth+1, i);
            list.pop_back();

        }
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
    combination(0, 0);

    return 0;
}