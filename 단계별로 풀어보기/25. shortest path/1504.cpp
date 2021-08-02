#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector < tuple <int, int, int> > Edges;
int V, E;
int u, v, w;

int main() {
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        Edges.push_back(make_tuple(u, v, w));


    }
}