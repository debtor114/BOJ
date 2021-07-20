#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int arr[20][20];
vector<int> p, sub, ans, A, B;

int main() {
    int N;
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        p.push_back(i);
    }

    for (int i = 0; i < N/2; i++) {
        sub.push_back(0);
        sub.push_back(1);
    }

    sort(sub.begin(), sub.end());

    do {
        // 팀 나누기
        for (int i = 0; i < sub.size(); i++) {
            if (sub[i] == 1)
                A.push_back(p[i]);

            else
                B.push_back(p[i]);
        }

        int sumA = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A.size(); j++) {
                if (i == j)
                    continue;
                sumA += arr[A[i]][A[j]];
            }
        }

        int sumB = 0;
        for (int i = 0; i < B.size(); i++)
        {
            for (int j = 0; j < B.size(); j++) {
                if (i == j)
                    continue;
                sumB += arr[B[i]][B[j]];
            }
        }

        ans.push_back(sumA-sumB);

    } while (next_permutation(sub.begin(), sub.end()));


    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << ans.front() << endl;
    return 0;
}