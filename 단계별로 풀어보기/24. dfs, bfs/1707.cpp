#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <int> adj_list[20001];
int visit[20001], colors[20001];
int V, E;
bool flag = true;

void init() {
    memset(visit, 0, sizeof(visit));
    memset(colors, 0, sizeof(colors));
    flag = true;
    for (int i = 1; i <= V; i++) 
        adj_list[i].clear();
}


void dfs(int start, int color) {
    visit[start] = 1;
    colors[start] = color;

    for (int i = 0; i < adj_list[start].size(); i++) {
        int u = adj_list[start][i];
        if (!visit[u]) dfs(u, !color);
        else {
            if (color == colors[u]) {
                flag = false;
                return;

            } 
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        
        for (int i = 1; i <= V; i++)
            if (!visit[i]) dfs(i, 0);

        if (flag) cout << "YES\n";
        else cout << "NO\n";

        init();
            
    }
    return 0;
}