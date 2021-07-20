// 막힌곳
// 인풋이 111111 이런식으로 들어왓을 때 scanf("%d", &board[i][j]) 로 하니까
// 111111이 1이 6개가 차례대로 배열에 들어오지 않고 111111이란 숫자가 한 배열에 들어가버렸다.
// 해결법 : 한 숫자씩 받을 때는 scanf("%1d", &board[i][j]); 처럼 써주면 된다.

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[25][25];
int visit[625];
vector <int> adj_list[625];
vector <int> houses;


int bfs(int s) {
    queue <int> q;
    int count = 1;

    visit[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i];
            if (visit[v] == 0) {
                q.push(v);
                visit[v] = 1;
                count++;
            }
        }
    }
    return count;

}

int main() {
    int N;
    scanf("%d", &N);

    // make board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    // make adj_list
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int u = i*N + j;
            int v;
            if (board[i][j] == 1) {
                if (board[i+1][j] && i < N-1) {
                    v = (i+1)*N + j;
                    adj_list[u].push_back(v);
                }

                if (board[i][j+1] && j < N-1) {
                    v = i*N + j+1;
                    adj_list[u].push_back(v);
                }

                if (board[i-1][j] && i > 0) {
                    v = (i-1)*N + j;
                    adj_list[u].push_back(v);
                }

                if (board[i][j-1] && j > 0) {
                    v = i*N + j-1;
                    adj_list[u].push_back(v);
                }
            }
            else continue;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int s = i*N + j;
            if (board[i][j] == 1 && visit[s] == 0) {
                houses.push_back(bfs(s));
            }
        }
    }
    sort(houses.begin(), houses.end());

    printf("%d\n", (int)houses.size());

    for (int i = 0; i < houses.size(); i++)
        printf("%d\n", houses[i]);

    return 0;
    
}