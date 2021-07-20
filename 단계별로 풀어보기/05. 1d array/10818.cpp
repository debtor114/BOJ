#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, temp, maxi, mini;
    vector <int> box;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        box.push_back(temp);
    }
    
    printf("%d %d\n", *min_element(box.begin(), box.end()), *max_element(box.begin(), box.end()));
    return 0;
}