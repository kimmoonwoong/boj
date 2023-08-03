#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	int n,s,r; cin >> n >> s >> r;
	vector<int> arr(n + 1, 1);

	for (int i = 0; i < s; i++) {
		int k; cin >> k;
		arr[k]--;
	}

	for (int i = 0; i < r; i++) {
		int c; cin >> c;
		arr[c]++;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			if (arr[i - 1] == 2) {
				arr[i]++;
				arr[i - 1]--;
			}
			else if (arr[i + 1] == 2) {
				arr[i]++;
				arr[i + 1]--;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] <= 0) ans++;
	}
	cout << ans;

}