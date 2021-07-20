#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int K;
    scanf("%d", &K);

    stack <int> s;
    while (K--) {
        int temp;
        scanf("%d", &temp);
        if (temp == 0) s.pop();
        else s.push(temp);
    }

    int sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    
    printf("%d\n", sum);
    return 0;
}