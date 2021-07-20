#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int row, col;
int tomatos;
int board[1050][1050];
int d[1002001], visit[1002001];
vector <int> adj_list[1000000];
vector <int> start_list;
vector <int> visit_order;

int BFS() {
    int count = 0;

    // 익은 토마토가 하나도 없는 경우
    if (start_list.size() < 1) return -1;

    queue <int> q;
    for (int i = 0; i < start_list.size(); i++) {
        d[start_list[i]] = 0;
        visit[start_list[i]] = 1;
        q.push(start_list[i]);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        visit_order.push_back(u);
        int v;
        for (int i = 0; i < adj_list[u].size(); i++) {
            v = adj_list[u][i];
            if (visit[v] == 0) {
                d[v] = d[u] + 1;
                visit[v] = 1;

                q.push(v);
            }
        }
    }
    count = d[visit_order.back()];

    if (visit_order.size() == tomatos) return count;
    else return -1;
}

int main() {
    scanf("%d %d", &row, &col);

    // 토마토판 받아오기
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] >= 0) tomatos++;
            if (board[i][j] == 1) start_list.push_back(row*i + j);
        }
    }

    // adj_list 만들기
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (board[i][j] >= 0) {
                int u = i*row + j;
                int v;
                if (i < col-1 && board[i+1][j] >= 0) {
                    v = (i+1)*row + j;
                    adj_list[u].push_back(v);
                }

                if (j < row-1 && board[i][j+1] >= 0) {
                    v = i*row + j+1;
                    adj_list[u].push_back(v);
                }

                if (i > 0 && board[i-1][j] >= 0) {
                    v = (i-1)*row + j;
                    adj_list[u].push_back(v);
                }

                if (j > 0 && board[i][j-1] >= 0) {
                    v = i*row + j-1;
                    adj_list[u].push_back(v);
                }
            }
        }
    }

    printf("%d\n", BFS());
    return 0;
}