#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N, M, ans;
    vector <int> numbers, answers;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp <= M)
            numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            for (int k = j+1; k < numbers.size(); k++) {
                int sum = numbers[i] + numbers[j] + numbers[k];
                answers.push_back(sum);
            }
        }
    }
    answers.erase(unique(answers.begin(), answers.end()), answers.end());

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] > M) answers[i] = -1;
    }

    sort(answers.begin(), answers.end());
    // for (int i = 0; i < answers.size(); i++) {
    //     printf("%d", answers[i]);
    // }

    ans = answers.back();
    printf("%d\n", ans);
    return 0;

}