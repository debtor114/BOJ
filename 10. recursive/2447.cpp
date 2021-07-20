#include <cstdio>

using namespace std;

#define MAX 6561

bool board[MAX][MAX];
int N;

                /*
                            1 1 1 2 2 2 3 3 3
                            1 1 1 2 2 2 3 3 3
                            1 1 1 2 2 2 3 3 3
                1 2 3       4 4 4 5 5 5 6 6 6 
                4 5 6  =>   4 4 4 5 5 5 6 6 6 
                7 8 9       4 4 4 5 5 5 6 6 6 
                            7 7 7 8 8 8 9 9 9 
                            7 7 7 8 8 8 9 9 9 
                            7 7 7 8 8 8 9 9 9 
                */

void recursive(int n, int x, int y) {
    if (n == 3) {
        if (board[x/3][y/3] == true) {
            for (int k = x; k < x+3; k++) {
                for (int l = y; l < y+3; l++) {
                    if (k == x+1 && l == y+1) 
                        board[k][l] = false;
                    else 
                        board[k][l] = true;
                }
            }        
        }
        else {
            for (int k = x; k < x+3; k++) {
                for (int l = y; l < y+3; l++) {
                    board[k][l] = false;
                }
            } 
        }
    }

    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                recursive(n/3, x + i*(n/3), y + j*(n/3));
            }
        }
    }
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }    
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = true;
            if (i == 1 && j ==1) board[i][j] = false;
        }
    }
    recursive(N, 0, 0);
    printBoard();
    return 0;

}