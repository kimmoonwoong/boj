#include <iostream>
#define MAX 5000000
using namespace std;

int arr[500][500];
int dp[500][500];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++)dp[0][i] = arr[0][i];
	for (int i = 1; i < n; i++) {
		int min = MAX;
		int index = 0;
		for (int j = 0; j < m; j++) 
			if (min > dp[i - 1][j]) {
				min = dp[i - 1][j];
				index = j;
			}
		for (int j = 0; j < m; j++) dp[i][j] = min;
		min = MAX;
		for (int j = 0; j < m; j++) {
			if (j == index) continue;
			if (min > dp[i - 1][j]) min = dp[i - 1][j];
		}
		dp[i][index] = min;
		for (int j = 0; j < m; j++) {
			dp[i][j] += arr[i][j];
		}
	}
	int ans = MAX;
	for (int i = 0; i < m; i++) ans = min(ans, dp[n - 1][i]);
	cout << ans;
	return 0;
}