#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector <int> adj_list[1001];
int bfs_visit[1001], dfs_visit[1001];
int V, E, start;


void dfs_stack(int start) {
    stack <int> s;
    s.push(start);

	while (!s.empty()) {
        int v = s.top();
        s.pop();
        
        if (!dfs_visit[v]) {
            printf("%d ", v);
            dfs_visit[v] = true;
        }
        
        for (int i = adj_list[v].size() - 1; i >= 0; i--) {
            int w = adj_list[v][i];
            if (!dfs_visit[w]) {
                s.push(w);
            }
        }
    }
}

void dfs (int start) {
    printf("%d ", start);
    dfs_visit[start] = true;

    for (int i = 0; i < adj_list[start].size(); i++) {
        int v = adj_list[start][i];
        if (dfs_visit[v] == false) {
            dfs(v);
        }
    }
}


void bfs(int start) {
    bfs_visit[start] = true;
    
    queue <int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        printf("%d ", u);

        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i];
            if (bfs_visit[v] == false) {
                bfs_visit[v] = true;
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

    for (int i = 0; i < V; i++) 
        sort(adj_list[i].begin(), adj_list[i].end());
    

    dfs_stack(start);
    printf("\n");
    bfs(start);
    printf("\n");
    return 0;
}