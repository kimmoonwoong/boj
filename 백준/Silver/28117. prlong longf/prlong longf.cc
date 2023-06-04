#include <iostream>
#include <string>


using namespace std;

int dp[81];
int main() {
	int n; cin >> n;
	string s; cin >> s;
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (s.substr(i, 8) == "longlong") {
			dp[i] = dp[i + 1] + dp[i + 8];
		}
		else dp[i] = dp[i + 1];
	}
	cout << dp[0];
}