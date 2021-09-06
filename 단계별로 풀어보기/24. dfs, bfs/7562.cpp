#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;


int visit[301][301];
int d[301][301];

vector < pair<int, int> > adj_list[301][301];

void init() {
    for (int i = 0; i < 301; i++) memset(visit[i], 0, sizeof(visit[i]));
    for (int i = 0; i < 301; i++) memset(d[i], 0, sizeof(d[i]));
    for (int i = 0; i < 301; i++) {
        for (int j = 0; j < 301; j++) {
            adj_list[i][j].clear();
        }
    }
}

void bfs (int x, int y, int desx, int desy) {
    visit[x][y] = 1;
    d[x][y] = 0;

    queue < pair <int, int> > q;
    
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair <int, int> u = q.front();
        q.pop();

        for (int i = 0; i < adj_list[u.first][u.second].size(); i++) {
            pair <int, int> v = adj_list[u.first][u.second][i];

            if (visit[v.first][v.second] == 0) {
                q.push(v);
                visit[v.first][v.second] = 1;
                d[v.first][v.second] = d[u.first][u.second] + 1;
            }

            if (v.first == desx && v.second == desy) return;
        }


    }

}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int I;
        cin >> I;
        for (int i = 0; i < I; i++) {
            for (int j = 0; j < I; j++) {
                if (i < I-2 && j < I-1) adj_list[i][j].push_back(make_pair(i+2, j+1));
                if (i < I-2 && j >= 1) adj_list[i][j].push_back(make_pair(i+2, j-1));
                if (i < I-1 && j < I-2) adj_list[i][j].push_back(make_pair(i+1, j+2));
                if (i < I-1 && j >= 2) adj_list[i][j].push_back(make_pair(i+1, j-2));
                if (i >= 2 && j < I-1) adj_list[i][j].push_back(make_pair(i-2, j+1));
                if (i >= 2 && j >= 1) adj_list[i][j].push_back(make_pair(i-2, j-1));
                if (i >= 1 && j < I-2) adj_list[i][j].push_back(make_pair(i-1, j+2));
                if (i >= 1 && j >= 2) adj_list[i][j].push_back(make_pair(i-1, j-2));
            }
        }

        int x, y, desx, desy;
        cin >> x >> y >> desx >> desy;

        bfs(x, y, desx, desy);

        cout << d[desx][desy] << "\n";

        init();
    }

    return 0;

}