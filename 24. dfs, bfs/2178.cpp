#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int maze[101][101];
bool visit[10201];
int d[10201];
vector <int> adj_list[10201];


void BFS(int start) {
    queue <int> q;
    visit[start] = true;
    d[start] = 1;

    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i];
            if (!visit[v]) {
                visit[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            maze[i][j] = s[j] - 48;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == 1) {
                int vertex = (M*i)+(j+1);
                if (i+1 < N  && maze[i+1][j] == 1) {
                    adj_list[vertex].push_back(vertex + M);
                }

                if (j+1 < M && maze[i][j+1] == 1) {
                    adj_list[vertex].push_back(vertex + 1);
                }

                if (i-1 >= 0 && maze[i-1][j] == 1) {
                    adj_list[vertex].push_back(vertex - M);
                }

                if (j-1 >= 0 && maze[i][j-1] == 1) {
                    adj_list[vertex].push_back(vertex - 1);
                }
            }

            else continue;
        }     
    }

    BFS(1);
    printf("%d\n", d[N*M]);
    return 0;

}