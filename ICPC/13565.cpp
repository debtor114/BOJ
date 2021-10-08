#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector < pair <int, int> > adj_list[1000][1000];
int visit[1000][1000];
int N, M;

bool bfs (int x, int y) {
    visit[x][y] = 1;

    queue < pair <int, int> > Q;
    Q.push(make_pair(x, y));

    while (!Q.empty()) {
        pair <int, int> u = Q.front();
        Q.pop();

        for (int i = 0; i < adj_list[u.first][u.second].size(); i++) {
            pair <int, int> v = adj_list[u.first][u.second][i];
            if (!visit[v.first][v.second]) {
                visit[v.first][v.second] = 1;
                Q.push(v);
            }

            if (v.first == N-1) return true;
        }
    }

    return false;
}

int main() {
    scanf("%d %d", &N, &M);

    int board[1000][1000] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                if (i-1 >= 0 && board[i-1][j] == 0) adj_list[i][j].push_back(make_pair(i-1, j));
                if (j-1 >= 0 && board[i][j-1] == 0) adj_list[i][j].push_back(make_pair(i, j-1));
                if (i+1 < N && board[i+1][j] == 0) adj_list[i][j].push_back(make_pair(i+1, j));
                if (j+1 < M && board[i][j+1] == 0) adj_list[i][j].push_back(make_pair(i, j+1));
            }
        }
    }

    bool flag = false;

    for (int i = 0; i < M; i++) {
        if (board[0][i] == 0) flag = bfs(0, i);
        if (flag) break;
    }

    if (flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}