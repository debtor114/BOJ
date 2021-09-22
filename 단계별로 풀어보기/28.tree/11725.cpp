#include <iostream>
#include <vector>

using namespace std;

vector <int> adj_list[100001];
int visit[100001], parent[100001];


void dfs(int start) {
    visit[start] = 1;

    for (int i = 0; i < adj_list[start].size(); i++) {
        int v = adj_list[start][i];
        if (!visit[v]) {
            parent[v] = start;
            dfs(v);
        }
    }

}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
    }

    for (int i = 1; i <= N; i++) if (!visit[i]) dfs(i);


    for (int i = 2; i <= N; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;

}