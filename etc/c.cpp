#include <vector>
#include <iostream>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER_ARRAY arr
 *  3. INTEGER_ARRAY query_values
 */

int kth[2000000];

vector<int> solve(int X, vector<int> arr, vector<int> query_values) {
    
    vector <int> answer;
    
    for (int i = 0; i < query_values.size(); i++) {
        
        if (query_values[i] > arr.size()) {
            answer.push_back(-1);
            continue;
        }
        
        int count = 0;     
        int min = 0, max = arr.size();
        
        for (int j = query_values[i]+1; j < arr.size(); j++) {
            if (kth[j] > 0) {
                max = kth[j];
                break;
            }
        }
        
        for (int j = query_values[i]-1; j >= 0; j--) {
            if (kth[j] > 0) {
                min = kth[j];
                count = j;
                break;
            }
        }
        
        
        for (int j = min; j < max; j++) {
            if (count == query_values[i]) {
                kth[query_values[i]] = j+1;
                answer.push_back(j+1);
                break;
            }

            if (arr[j] == X) count++;
        }

                
        
        
        if (count < query_values[i]) answer.push_back(-1); 
    }


    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    
    return answer;

}
int main() {

    int X;
    vector <int> arr, query;

    cin >> X;
    for (int i = 0; i < X; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    for (int i = 0; i < X; i++) {
        int input;
        cin >> input;
        query.push_back(input);
    }

    solve(X, arr, query);

}