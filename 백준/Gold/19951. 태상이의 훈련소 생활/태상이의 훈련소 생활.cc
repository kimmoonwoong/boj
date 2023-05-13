#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> arr(100001);
	vector<int> partial(100001);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, k; cin >> a >> b >> k;
		partial[a] += k;
		partial[b + 1] -= k;
	}
	partial_sum(partial.begin(), partial.end(), partial.begin());
	for (int i = 1; i <= n; i++) {
		arr[i] += partial[i];

		cout << arr[i] << " ";
	}
	return 0;
}