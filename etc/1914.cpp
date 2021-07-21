#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

void hanoi(int N, int src, int dst, int via) {
    if (N == 1) printf("%d %d\n", src, dst);
    else {
        hanoi(N-1, src, via, dst);
        printf("%d %d\n", src, dst);
        hanoi(N-1, via, dst, src);
    }

}

int main() {
    int N;
    scanf("%d", &N);
    
    string answer = to_string(pow(2, N));
    int idx = answer.find('.');
    answer = answer.substr(0, idx);
    answer[answer.length()-1] -= 1;

    printf("%s\n", answer.c_str());
    if (N <= 20) hanoi(N, 1, 3, 2);

    return 0;

}