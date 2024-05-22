#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

ll dp[1001][26];
ll mod = 1e9 + 7;
void solve() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < 26; i++) dp[1][i] = 1;

	for (int i = 2; i <= m; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				if (abs(j - k) >= n) {
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) %	mod;
				}
			}
		}
	}

	ll ans = 0;

	for (int i = 0; i < 26; i++) ans += dp[m][i];
	cout << ans % mod;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
}