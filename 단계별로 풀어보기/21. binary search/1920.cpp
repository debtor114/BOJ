#include <cstdio>
#include <algorithm>
#include <cstdbool>
#include <vector>

using namespace std;

int target;
vector <int> v;

bool bsearch(int start, int end) {
    int mid = (start+end) / 2;

    if (target < v[start] || target > v[end]) return false;

    if (target < v[mid]) return bsearch(start, mid);
    else if (target > v[mid]) return bsearch(mid+1, end);
    else return true;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &target);
        if (bsearch(0, N-1)) printf("1\n");
        else printf("0\n"); 
    }

    return 0;

}