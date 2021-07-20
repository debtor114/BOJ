#include <cstdio>

using namespace std;

int board[128][128];
int blue, white;

void check(int size, int x, int y) {

    int c = board[x][y];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[x+i][y+j] == c) continue;
            else {
                int new_size = size/2;
                check(new_size, x, y);
                check(new_size, x+new_size, y);
                check(new_size, x, y+new_size);
                check(new_size ,x+new_size, y+new_size);
                return;
            }
        }
    }

    c == 1 ? blue++ : white++;

}


int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    check(N, 0, 0);

    printf("%d\n%d\n", white, blue);
    return 0;


}