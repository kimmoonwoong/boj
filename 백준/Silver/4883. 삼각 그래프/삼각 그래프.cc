#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;

int arr[100001][3];
int dp[100001][3];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	while (1) {
		int n; cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) cin >> arr[i][j];
		for (int i = 0; i < n; i++) memset(dp[i], 0, sizeof(int) * 3);
		
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][1] + arr[0][2];
		dp[0][0] = INT16_MAX;
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
			dp[i][1] = min({ dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] }) + arr[i][1];
			dp[i][2] = min({ dp[i][1], dp[i - 1][1], dp[i - 1][2] }) + arr[i][2];
		}
		cout << t << ". " << dp[n - 1][1] << "\n";
		t++;
	}
	return 0;
}	