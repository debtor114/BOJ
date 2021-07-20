#include <cstdio>

using namespace std;

int board[2190][2190];
int minus, zero, plus;

void recur (int size, int x, int y) {

    int c = board[x][y];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[x+i][y+j] == c) continue;
            else {
                int new_size = size/3;
                recur(new_size, x, y);
                recur(new_size, x+new_size, y);                   
                recur(new_size, x+2*new_size, y);

                recur(new_size, x, y+new_size);
                recur(new_size, x+new_size, y+new_size);                   
                recur(new_size, x+2*new_size, y+new_size);

                recur(new_size, x, y+2*new_size);
                recur(new_size, x+new_size, y+2*new_size);                   
                recur(new_size, x+2*new_size, y+2*new_size);             
                return;
            }
        }
    }

    if (c == -1) minus++;
    else if (c == 0) zero++;
    else plus++;

}


int main () {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    recur(N, 0, 0);
    printf("%d\n%d\n%d\n", minus, zero, plus);
    return 0;

}