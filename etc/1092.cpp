#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    vector <int> crain, boxes;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        crain.push_back(input);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int input;
        scanf("%d", &input);
        boxes.push_back(input);
    } 

    sort(crain.begin(), crain.end());
    sort(boxes.begin(), boxes.end());

    if (crain.back() < boxes.back()) printf("-1\n");
    else {
        printf("%d\n", (int)ceil((double)M/(double)N));
    }   
    return 0;
}