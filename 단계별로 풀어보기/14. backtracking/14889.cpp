#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int arr[41][41];
vector<int> ans, A, B(20), group;
int N;


void combination(int depth, int index) {


    if (depth == N/2) {
        int sumA = 0;
        for (int i = 0; i < N/2 -1; i++) {
            for (int j = i+1; j < N/2; j++) {
                sumA += arr[A[i]][A[j]];
                sumA += arr[A[j]][A[i]];
            }
        }

        int sumB = 0;
        set_difference(group.begin(), group.end(), A.begin(), A.end(), B.begin());

        for (int i = 0; i < N/2-1; i++) {
            for (int j = i+1; j < N; j++) {
                sumB += arr[B[i]][B[j]];
                sumB += arr[B[j]][B[i]];
            }
        } 

        // for (int i = 0; i < N/2; i++) {
        //     cout << A[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < N/2; i++) {
        //     cout << B[i] << " ";
        // }
        // cout << "\n";

        // cout << "abs: " << abs(sumA-sumB) << endl;

        B.clear();
        ans.push_back(abs(sumA-sumB));       
    }

    for (int i = index; i <= N; i++) {
        A.push_back(i);
        combination(depth+1, i+1);
        A.pop_back();
    }
    
}


int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++)   
        group.push_back(i);


   combination(0, 1);
    
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    return 0;
}