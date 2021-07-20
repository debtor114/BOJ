#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;


int main() {
    int dp[101][100001];
    int n, k;
    pair< int, int > item[101];
    
	
    cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> item[i].first >> item[i].second;
	}
	
    sort(item, item + n + 1);

		for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (item[i].first > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i].first] + item[i].second);
		}
	}
	return dp[n][k];
}