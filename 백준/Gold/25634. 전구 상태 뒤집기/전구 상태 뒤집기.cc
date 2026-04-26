#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int sum = 0;
	vector<int> arr1(n + 1);
	vector<int> arr2(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr2[i];
		if (arr2[i])
			sum += arr1[i];
	}
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		if (arr2[i]) {
			dp[i] = -arr1[i];
			dp[i] = max(dp[i], dp[i - 1] + dp[i]);
		}
		else {
			dp[i] = arr1[i];

			dp[i] = max(dp[i], dp[i - 1] + dp[i]);
		}
	}

	int maxs = -1e9;
	for (int i = 1; i <= n; i++)
	{
		maxs = max(maxs, dp[i]);
	}
	cout << maxs + sum;
}