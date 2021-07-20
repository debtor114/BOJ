#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector <int> results;

void recursive(vector <int> &op_stacks, int start, int depth) {
    if (depth == N-1) return;
    else {
        for (int i = start; i < op_stacks.size(); i++) {
            

        }
    }
}

int main() {
    vector <int> num, operators, op_stacks;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d ", &tmp);
        num.push_back(tmp);
    }

    scanf("%d %d %d %d", &operators[0], &operators[1], &operators[2], &operators[3]);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < operators[i]; j++) {
            op_stacks.push_back(i+1);
        }
    }

    recursive(op_stacks, op_stacks[0], 0);
    return;


}