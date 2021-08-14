#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int visit[10];
int board[10][10];

int N, previous;
vector <long long> d, order;

void traversal(int depth) {
    
    if (depth == N) {
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += board[order[i]][order[(i+1)%N]];
        }

        d.push_back(sum);
        return;
    }


    for (int i = 0; i < N; i++) {
        
        if (!visit[i]) {
            if (depth > 0) {
                if (board[previous][i]) {
                    order.push_back(i);
                    visit[i] = 1;
                    previous = i;
                    traversal(depth+1);
                    order.pop_back();
                    visit[i] = 0;
                }
            }

            else {
                order.push_back(i);
                visit[i] = 1;
                previous = i;
                traversal(depth+1);
                order.pop_back();
                visit[i] = 0;
            }
        }
    }

    


}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    traversal(0);
    sort(d.begin(), d.end());
    cout << d[0] << endl;
    return 0;


}