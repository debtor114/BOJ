#include <cstdio>
#include <vector>

using namespace std;

int dfs_all();
void dfs(int);

int V, E;
vector <int> adj_list[1001];
int visit[1001];



int dfs_all() {
    int cc = 0;
    for (int i = 1; i <= V; i++) {
        if (visit[i] == 0) {
            cc++;
            dfs(i);
        }
    }
    return cc;
}

void dfs(int s) {
    visit[s] = 1;

    for (int i = 0; i < adj_list[s].size(); i++) {
        int v = adj_list[s][i];
        if (visit[v] == 0) {
            dfs(v);
        }
    }

}

int main() {
    scanf("%d %d", &V, &E);

    int u, v;
    for (int i = 1; i <= E; i++) {
        scanf("%d %d", &u, &v);
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    printf("%d\n", dfs_all());
    return 0;
}