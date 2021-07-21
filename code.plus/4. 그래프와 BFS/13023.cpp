#include <iostream>
#include <vector>

using namespace std;

int visit[2001];
vector <int> adj_list[2001];

int V, E;

void dfs(int start) {
    int u = start;
    visit[u] = 1;

    for (int i = 0; i < adj_list[u].size(); i++) {
        int v = adj_list[u][i];
        if (visit[v] == 0) dfs(v);
    }
}

int dfs_all() {
    int c = 1;
    for (int i = 0; i < V; i++) {
        if (visit[i] == 0)
            dfs(i);

        else c++;
    }

    return c;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    if (V == dfs_all()) cout << "1" << endl;
    else cout << "0" << endl;

    return 0;
}