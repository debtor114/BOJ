#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v, list;

int visit[10];

int N, M;

void permutation(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
            printf("%d ", list[i]);

        printf("\n");

        return;
    }

    int prev_num= -1;

    for (int i = 0; i < N; i++) {
        if (!visit[i] && prev_num != v[i]) {
            list.push_back(v[i]);
            prev_num = v[i];
            visit[i] = 1;
            permutation(depth+1);
            list.pop_back();
            visit[i] = 0;
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
    permutation(0);

    return 0;
}