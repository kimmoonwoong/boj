#include <iostream>
#include<cmath>
using namespace std;
int dp[10000001];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;


	dp[1] = 1;
	dp[2] = 2;
	for (int i = 2; i <= n; i++) {
		int k = i + ceil(i / 2);
		if (dp[i + 1] == 0) dp[i + 1] = dp[i] + 1;
		if (k <= n) {
			dp[k] = dp[i] + 1, dp[k];
		}
	}
	if (dp[n] <= k) cout << "minigimbob";
	else cout << "water";
	return 0;
}	