#include <iostream>
#include <map>

using namespace std;
int INF = 1e5;
int arr[1001];
int dp[1001];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	fill(dp, dp + n, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j >= n) continue;			
			dp[i + j] = min(dp[i] + 1, dp[i + j]);
		}
	}
	if (dp[n - 1] == INF) cout << -1;
	else cout << dp[n - 1];
}