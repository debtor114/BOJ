#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <iterator>

using namespace std;

int board[9][9];
vector < pair <int, int> > blank;

void sudoku(int i , int j, int depth) {
    vector <int> possible(9, 0);
    vector <int> ans;
    vector <int>::iterator iter;

    
    if (depth == blank.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }


    else {
        // 가로, 세로에 있는 모든 숫자 체크하기
        for (int k = 1; k < 9; k++) {
            if (board[i][(j+k)%9]) possible[board[i][(j+k)%9] - 1] = 1;
            if (board[(i+k)%9][j]) possible[board[(i+k)%9][j] - 1] = 1;
        }

        // 같은 사각형에 있는 모든 숫자 체크하기
        int sRow = 3*(i/3);
        int sCol = 3*(j/3);
        for (int n = 0; n < 3; n++) {
            for (int m = 0; m < 3; m++) {
                if (board[sRow+n][sCol+m]) possible[board[sRow+n][sCol+m] - 1] = 1;
            }
        }

        for (int k = 0; k < 9; k++)
            if (possible[k] == 0) ans.push_back(k+1);

        // 검사식, 들어갈 수 있는 숫자가 하나도 없는 경우 (= 위에서 잘못된 경우)
        if (ans.empty()) return;

        for (int k = 0; k < ans.size(); k++) {
            board[i][j] = ans[k];
            sudoku(blank[depth+1].first, blank[depth+1].second, depth+1);
            
            // 잘못되었으면 돌려놓기
            board[i][j] = 0;
        }
    }
}

int main () {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 0)
                blank.push_back(make_pair(i, j));
        }
    }

    sudoku(blank[0].first, blank[0].second, 0);
    return 0;
}