#include <iostream>
#include <vector>

using namespace std;

vector <char> adj_list[27];


void postorder (int u) {
    if (adj_list[u][0] != '.') postorder(adj_list[u][0]);
    if (adj_list[u][1] != '.')postorder(adj_list[u][1]);
    printf("%c", u+65);
}

void preorder (int u) {
    printf("%c", u+65);
    if (adj_list[u][0] != '.') preorder(adj_list[u][0]);
    if (adj_list[u][1] != '.') preorder(adj_list[u][1]);
}

void inorder (int u) {
    if (adj_list[u][0] != '.') inorder(adj_list[u][0]);
    printf("%c", u+65);
    if (adj_list[u][1] != '.') inorder(adj_list[u][1]);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char u;
        cin >> u;
        for (int j = 0; j < 2; j++) {
            char v;
            cin >> v;
            adj_list[u-65].push_back(v);
        }
    }

    preorder(0);
    inorder(0);
    postorder(0);

    return 0;
}