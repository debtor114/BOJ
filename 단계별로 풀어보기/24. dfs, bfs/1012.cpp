#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void DFS();
void DFS_VISIT(int);
void init();

int ground[51][51];
bool visit[2601];
vector <int> adj_list[2601];

int N, M, K, count;

void DFS() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int vertex = (M*i)+(j+1);
            if (!visit[vertex] && ground[i][j] == 1) {
                count++;
                DFS_VISIT(vertex);
            }
        }
    }
}

void DFS_VISIT(int start) {
    visit[start] = true;
    
    for (int i = 0; i < adj_list[start].size(); i++) {
        int u = adj_list[start][i];
        if (!visit[u]) {
            DFS_VISIT(u);
        }
    }
}

void init() {
    for (int i = 0; i < 2601; i++) {
        visit[i] = false;
        adj_list[i].clear();
    }

    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            ground[i][j] = 0;
        }
    }
    
    count = 0;
}


int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        init();
        scanf("%d %d %d", &N, &M, &K);
        for (int i = 0; i < K; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            ground[x][y] = 1;

        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (ground[i][j] == 1) {
                    int vertex = (M*i)+(j+1);
                    if (i+1 < N  && ground[i+1][j] == 1) {
                        adj_list[vertex].push_back(vertex + M);
                    }

                    if (j+1 < M && ground[i][j+1] == 1) {
                        adj_list[vertex].push_back(vertex + 1);
                    }

                    if (i-1 >= 0 && ground[i-1][j] == 1) {
                        adj_list[vertex].push_back(vertex - M);
                    }

                    if (j-1 >= 0 && ground[i][j-1] == 1) {
                        adj_list[vertex].push_back(vertex - 1);
                    }
                }

                else continue;
            }     
        }

        DFS();
        printf("%d\n", count);
    } 
    return 0;
}