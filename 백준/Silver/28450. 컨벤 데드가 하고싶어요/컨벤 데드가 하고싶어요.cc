#include<iostream>
#include <algorithm>
using namespace std;

long long arr[1001][1001];
long long dp[1001][1001];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int h; cin >> h;
	dp[0][0] = arr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j - 1 < 0 && i - 1 < 0) continue;
			if (j - 1 < 0 && i - 1 >= 0) dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j - 1 >= 0 && i - 1 < 0) dp[i][j] = dp[i][j - 1] + arr[i][j];
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
			}
		}
	}

	if (dp[n - 1][m - 1] <= h) {
		cout << "YES" << "\n";
		cout << dp[n - 1][m - 1];
	}
	else {
		cout << "NO";
	}
}