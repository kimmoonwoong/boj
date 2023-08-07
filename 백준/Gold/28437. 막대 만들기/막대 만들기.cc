#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
long long dp[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		dp[k] = 1;
	}
	for (int i = 2; i <= 100000; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) {
				if (i != j) {
					dp[i] += dp[j];
				}
				if (j != i / j) {
					if(i != i / j) dp[i] += dp[i / j];
				}
			}
		}
	}

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l; cin >> l;
		cout << dp[l] << " ";
	}
}