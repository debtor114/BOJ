#include <cstdio>
#include <algorithm>

int N, ans;

void nQueen(int m, int n, int qcount, int board[][15])  {
    
    // 퀸을 놓을 수 없는 경우
    if (board[m][n] < 0) return;

    // 퀸을 놓을 수 있는 경우
    else {
        // 퀸 놓기
        board[m][n] = 0;
        qcount++;

        // 퀸 다 놓았으면 return
        if (qcount == N) {
           ans++;
           return;
        }

        // 퀸을 놓으므로서 다음 퀸을 놓을 수 있는 자리 제한하기
        for (int i = 1; i < N; i++) {
            if (m+i < N) board[m+i][n]--;
            if (n+i < N) board[m][n+i]--;
            if (m+i < N && n+i < N) board[m+i][n+i]--;
            if (m+i >=0 && n-i >=0) board[m+i][n-i]--;
        }

        // 다음 줄로 넘어가기
        for (int i = 0; i < N; i++) {
            nQueen(m+1, i, qcount, board);
        }

        // 다시 퀸 빼고 다음 퀸을 놓을 수 있는 자리 수정하기
        board[m][n] = 0;
        for (int i = 1; i < N; i++) {
            if (m+i < N) board[m+i][n]++;
            if (n+i < N) board[m][n+i]++;
            if (m+i < N && n+i < N) board[m+i][n+i]++;
            if (m+i >=0 && n-i >=0) board[m+i][n-i]++;
        }
    }
}


int main() {
    scanf("%d", &N);
    int board[15][15];
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            board[i][j] = 0;
        
    // ([0,0]부터 [0,N-1]까지 첫 퀸 자리 선정하기)
    for (int i = 0; i < N; i++)
        nQueen(0, i, 0, board);

    printf("%d\n", ans);
    return 0;
}