#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector <int> v[11];
vector <int> list;

int visit[11];
int N, mini = 99999;

void recursive (int depth, int next) {

    if (depth == N) {
        int sum = 0;
        for (int i = 0; i < list.size(); i++) {
            sum += list[i];
            cout << list[i] << " ";
        }
        cout << endl;

        if (mini > sum) mini = sum;

        return;
    }


    int i = next;
    visit[i] = 1;

    for (int j = 0; j < N; j++) {
        if (v[i][j] != 0 && visit[j] == 0) {
            list.push_back(v[i][j]);
            recursive(depth+1, j);
            list.pop_back();
        } 
    }
        
    

}


int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            v[i].push_back(input);
        }
    }

    v[N] = v[0];

    recursive(0, 0);

    cout << mini << endl;

}