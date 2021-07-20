#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    string s;
    vector <int> score;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> s;
        int sum = 0;
        int accumulate = 1;
        
        for(int i = 0; i < s.length(); i++) {
            if (i == 0) {
                if (s[i] == 'O') {
                    sum += accumulate;
                    accumulate++;
                    continue;
                }
                else continue;
            }
            // 전 문제와 이번문제를 동시에 체크해야함
            if (s[i-1] == 'O' && s[i] == 'O') {
                sum += accumulate;
                accumulate++;
            }

            else if (s[i-1] != 'O' && s[i] == 'O') {
                accumulate = 1;
                sum += accumulate;
                accumulate++;
            }

            else {
                accumulate = 1;
            }
        }
        score.push_back(sum);
    }

    for (int i = 0; i < score.size(); i++)
        cout << score[i] << endl;

    return 0;
}