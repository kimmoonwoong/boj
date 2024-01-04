#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<double, double>
#define ll long long
using namespace std;




int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> arrA(n + 1);
	vector<int> arrB(n + 1);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;

		if (k > 0) {
			arrA[k - 1] += 1;
		}
		else {
			arrB[-k + 1] += 1;
		}
	}
	for (int i = n; i >= 1; i--) arrA[i - 1] += arrA[i];
	for (int i = 1; i <= n - 1; i++) arrB[i + 1] += arrB[i];

	vector<int> ans;
	for (int i = 0; i <= n; i++) {
		if (arrA[i] + arrB[i] == i) ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int k : ans) cout << k << " ";
	return 0;
}