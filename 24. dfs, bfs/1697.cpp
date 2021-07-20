#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int visit[400004], d[400004];
vector <int> adj_list[400004];

int bfs(int start, int dest) {
    queue <int> q;
    int ans;

    d[start] = 0;
    visit[start] = 1;
    q.push(start);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == dest) {
            ans = d[u];
            break;
        }

        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i];
            if (visit[v] == 0) {
                visit[v] = 1;
                d[v] = d[u] + 1;
                if (v > 200000) continue;
                q.push(v);
                // printf("d[%d]: %d ", v, d[v]);
            }
        }
        //printf("\n");
    }
    return ans;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    
    adj_list[0].push_back(1);
    for (int i = 1; i < 400004; i++) {
        adj_list[i].push_back(i+1);
        adj_list[i].push_back(i-1);
        adj_list[i].push_back(2*i);
    }
    
    printf("%d\n", bfs(N, K));
    return 0;
}