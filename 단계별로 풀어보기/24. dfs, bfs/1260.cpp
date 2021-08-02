#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

vector <int> adj_list[1001];
int visit[1001];
int V, E, start;


void dfs (int start) {
    printf("%d ", start);
    visit[start] = 1;

    for (int i = 0; i < adj_list[start].size(); i++) {
        int v = adj_list[start][i];
        if (visit[v] == 0) {
            dfs(v);
        }
    }
}


void bfs(int start) {
    visit[start] = 1;
    
    queue <int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        printf("%d ", u);

        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i];
            if (visit[v] == 0) {
                visit[v] = 1;
                q.push(v);

            }
        }
    }
}



int main() {
    scanf("%d %d %d", &V, &E, &start);
    for (int i = 0; i < E; i++) {
        int src, dst;
        scanf("%d %d", &src, &dst);

        adj_list[src].push_back(dst);
        adj_list[dst].push_back(src);
    }

    for (int i = 1; i <= V; i++) 
        sort(adj_list[i].begin(), adj_list[i].end());
    

    dfs(start);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    bfs(start);
    printf("\n");
    return 0;
}