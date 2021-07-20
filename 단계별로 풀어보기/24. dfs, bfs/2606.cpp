#include <cstdio>
#include <vector>

using namespace std;

int E, V, count;
vector <int> adj_list[101];
bool visit[101];

void DFS(int start) {
    visit[start] = true;

    for (int i = 0; i < adj_list[start].size(); i++) {
        int u = adj_list[start][i];
        if (!visit[u]) {
            count++;
            DFS(u);
        }
    }

}

int main() {
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int V1, V2;
        scanf("%d %d", &V1, &V2);
        adj_list[V1].push_back(V2);
        adj_list[V2].push_back(V1);
    }

    DFS(1);
    printf("%d\n", count);
    return 0;
}