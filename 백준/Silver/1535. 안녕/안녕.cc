#include <iostream>
#include <string>
using namespace std;
int arr[21];
int arr2[21];
int dp[101];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) cin >> arr2[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 100; j >= arr[i]; j--) {
			dp[j] = max(dp[j], dp[j - arr[i]] + arr2[i]);
		}
	}
	cout << dp[99];
}