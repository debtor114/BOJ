#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v, list;


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
        if (prev_num != v[i]) {
            list.push_back(v[i]);
            prev_num = v[i];
            permutation(depth+1);
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
    permutation(0);

    return 0;
}