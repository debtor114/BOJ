#include <iostream>
#include <tuple>
#include <vector>
#include <cstdbool>

using namespace std;


vector <tuple <long, long, long> > Edge;

int V, E;
int u, v, w;

long long d[504];
long long INF = 20000000000000000;

bool BellmanFord() {

    for (int i = 1; i <= V; i++) {
        d[i] = INF;
    }

    d[1] = 0; 

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            u = get<0>(Edge[j]);
            v = get<1>(Edge[j]);
            w = get<2>(Edge[j]);

            if (d[u] != INF && d[v] > d[u] + w) 
                d[v] = d[u] + w;
        }
    }

    for (int i = 0; i < E; i++) {

        u = get<0>(Edge[i]);
        v = get<1>(Edge[i]);
        w = get<2>(Edge[i]);

        if (d[u] != INF && d[v] > d[u] + w) return false;       
    }

    return true;

}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        Edge.push_back(make_tuple(u, v, w));
    }


    if (BellmanFord()) {
        for (int i = 2; i <= V; i++) {
            if (d[i] == INF) cout << "-1" << endl;
            else cout << d[i] << endl;
        }
        
    }
    else  cout << "-1" << endl;


    return 0;

}