#include <iostream>
using namespace std;
int arr[1025][1025];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		for (int j = x1; j <= x2; j++) {
			sum += arr[j][y2] - arr[j][y1 - 1];
		}
		cout << sum << "\n";
	}
	return 0;
}