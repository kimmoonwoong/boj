#include <iostream>

using namespace std;

int arr[100][100];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				if (cnt) {
					ans += cnt / 2 + 1;
					cnt = 0;
				}
			}
			else if (j == 0 || arr[i][j] != arr[i][j - 1]) {
				cnt++;
			}
				
		}
		if (cnt) {
			ans += cnt / 2 + 1;
		}
	}
	cout << ans;
	return 0;
}