#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdbool>

using namespace std;

bool visit[10000], prime[50000];
int d[10000];

vector <int> adj_list[10000];


void bfs (int start) {

    queue <int> q;

    visit[start] = true;
    d[start] = 0;
    q.push(start);

    int u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        
        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i];
            if (!visit[v]) {
                q.push(v);
                visit[v] = true;
                d[v] = d[u] + 1;
            }  
        }
    }
}

void seive() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 4; i < 50000; i += 2)
        prime[i] = false;

    for (int i = 2; i*i < 50000; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= 50000; j += i)
                prime[j] = false;
        }
    }
}

void isConnected(int num) {
    string p = to_string(num);

    for (int i = 1000; i < 10000; i++) {
        int c = 0;

        if (prime[i] == true) {
            for (int j = 0; j < 4; j++) {
                if (to_string(i)[j] != p[j]) c++;
            }

            if (c < 2) adj_list[num].push_back(i);
        }
    }

}

int main() {
    int T;
    cin >> T;

    seive();

    for (int i = 1000; i < 10000; i++) {
        if (prime[i]) isConnected(i);
    }


    while (T--) {
        memset(d, 0, sizeof(d));
        memset(visit, false, sizeof(visit));

        int src, dest;
        cin >> src >> dest;

        if (src == dest) {
            cout << "0" << endl;
            continue;
        }

        bfs(src);

        if (d[dest] > 0) cout << d[dest] << endl;
        else cout << "Impossible" << endl;

    }

    return 0;
}