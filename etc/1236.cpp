#include <cstdio>

using namespace std;

char board[50][50];

int main () {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &board[i][j]);
        }
    }

}