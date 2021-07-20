#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

int d[1000000], visit[1000000];
vector <int> adj_list[1000000];
int board[100][100][100];

int tomatos;
vector <int> start_list, trav_order;


int bfs() {

    if (start_list.empty()) return -1;

    queue <int> q;

    for (int i = 0; i < start_list.size(); i++) {
        int start = start_list[i];
        q.push(start);
        d[start] = 0;
        visit[start] = 1;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        trav_order.push_back(u);
        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i];
            if (visit[v] == 0) {
                d[v] = d[u] + 1;
                visit[v] = 1;
                q.push(v);
            }
        }
    }

    if (tomatos ==trav_order.size()) return d[trav_order.back()];
    else return -1;

}

int main() {
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &board[k][i][j]);
                if (board[k][i][j] >= 0) tomatos++;
                if (board[k][i][j] == 1) start_list.push_back(k*N*M + i*M + j);
            }
        }
    }

// printf("\n");
//     for (int k = 0; k < H; k++) {
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < M; j++) {
//                 printf("%d ", board[k][i][j]);   
//             }
//             printf("\n");
//         }
//         printf("%d번째 판\n", k);
//     }

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[k][i][j] >= 0) {
                    int u = k*M*N + i*M + j;
                    int v;
                    // 앞
                    if (k < H-1 && board[k+1][i][j] >= 0) {
                        v = (k+1)*M*N + i*M + j;
                        adj_list[u].push_back(v);
                    }

                    // 뒤
                    if (k > 0 && board[k-1][i][j] >= 0) {
                        v = (k-1)*M*N + i*M + j;
                        adj_list[u].push_back(v);
                    }

                    // 위
                    if (i < N-1 && board[k][i+1][j] >= 0) {
                        v = k*M*N + (i+1)*M + j;
                        adj_list[u].push_back(v);
                    }

                    // 아래
                    if (i > 0 && board[k][i-1][j] >= 0) {
                        v = k*M*N + (i-1)*M + j;
                        adj_list[u].push_back(v);
                    }

                    // 좌
                    if (j < M-1 && board[k][i][j+1] >= 0) {
                        v = k*M*N + i*M + j+1;
                        adj_list[u].push_back(v);
                    }

                    // 우
                    if (j > 0 && board[k][i][j-1] >= 0) {
                        v = k*M*N + i*M + j-1;
                        adj_list[u].push_back(v);
                    }

                }
            }
        }
    }

    // for (int i = 0; i < M*N*H; i++) {
    //     printf("adj_list[%d]: ", i);
    //     for (int j = 0; j < adj_list[i].size(); j++) {
    //         printf("%d ", adj_list[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", bfs());

    // for (int i = 0; i < M*N*H; i++) {
    //     printf("d[%d]: %d\n", i, d[i]);
    // }
    return 0;

}