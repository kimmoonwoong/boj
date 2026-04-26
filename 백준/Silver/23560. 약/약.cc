#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> dp(n + 1);
	dp[1] = 2;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] * 2 + dp[i - 1];
	}
	cout << dp[n];
}