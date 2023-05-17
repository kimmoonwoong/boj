#include <iostream>
using namespace std;
int arr[1025][1025];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) arr[i][j] += arr[i][j - 1];
	}
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int ans = 0;
		for (int i = x1; i <= x2; i++) ans += (arr[i][y2] - arr[i][y1 - 1]);
		cout << ans << "\n";
	}
	return 0;
}