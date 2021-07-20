#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

// sort 기준
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

int getAverage(vector<int> &arr, int N) {
    if (N == 1) return arr[0];
    int average, total;
    total = 0;
    for (int i = 0; i < N; i++) {
        total += arr[i];
    }
    average = round(total / (double)N);
    // printf("average: %f, total: %f\n", average, total);
    return average;
}

int getMiddleNumber(vector <int> &arr, int N) {
    if (N == 1) return arr[0];
     int centre = arr[N/2];
     return centre;
}

int getModeNumber(vector <int> &arr, int N) {
    if (N == 1) return arr[0];
    vector < pair <int, int> > maxNum;
    int count = 1;

    for (int i = 1; i < N+1; i++) {
        if (arr[i] == arr[i-1]) count++;
        else {
            maxNum.push_back(make_pair(count, arr[i-1]));
            count = 1;
        }
    }

    sort(maxNum.begin(), maxNum.end(), comp);

    // for (int i = 0; i < maxNum.size(); i++)
    //     printf("%d: %d\n", maxNum[i].second, maxNum[i].first);

    if (maxNum[0].first == maxNum[1].first) return maxNum[1].second;
    else return maxNum[0].second;

}

int getRange(vector <int> &arr) {
    int range;
    range = arr.front() - arr.back();
    return range;

}

int main() {
    int N;
    vector<int> arr;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    int aver = getAverage(arr, N);
    int centre = getMiddleNumber(arr, N);
    int most = getModeNumber(arr, N);
    int range = getRange(arr);

    printf("%d\n%d\n%d\n%d\n", aver, centre, most, range);
    return 0;
    
}