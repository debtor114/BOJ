#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N;
    vector <int> ans;

    scanf("%d", &N);

    vector <bool> prime(100000000, 1);
    
    // 에라토스테네스의 체
    prime[0] = false;
    prime[1] = false;
    
    for (int i = 2; i <= 100; i++) {
        if (prime[i]) {
            for (int j = i * i; j < 33333333; j += i) {
                prime[j] = false;
            }
        }
    }

    int k = 2;
    while (N != 1) {
        if (N % k == 0 && prime[k] == true) {
            N /= k;
            ans.push_back(k);
            k = 2;
        }

        else k++;
    }

    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}