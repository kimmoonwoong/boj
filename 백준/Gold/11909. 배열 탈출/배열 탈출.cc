#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[2222][2222];
int dp[2222][2222];
int INF = 1e9;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	vector<vector<int>> dp(n, vector<int>(n,INF));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;

			if (i == 0) {
				int cur = map[i][j] < map[i][j - 1] ? 0 : map[i][j] - map[i][j - 1] + 1;
				dp[i][j] = min(dp[i][j], cur + dp[i][j - 1]);
			}
			else if (j == 0) {
				int cur = map[i][j] < map[i - 1][j] ? 0 : map[i][j] - map[i - 1][j] + 1;
				dp[i][j] = min(dp[i][j], cur + dp[i - 1][j]);
			}
			else {
				int cur1 = map[i][j] < map[i - 1][j] ? 0 : map[i][j] - map[i - 1][j] + 1;
				int cur2 = map[i][j] < map[i][j - 1] ? 0 : map[i][j] - map[i][j - 1] + 1;
				dp[i][j] = min({ cur1 + dp[i - 1][j], cur2 + dp[i][j - 1], dp[i][j]});
			}

		}
	}

	cout << dp[n - 1][n - 1];
}