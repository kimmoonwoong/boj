#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrA[1001];
int arrB[1001];
int main() {
	int t; cin >> t;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arrB[i];
	}

	vector<int> a;
	vector<int> b;

	for (int i = 0; i < n; i++) {
		int sum = arrA[i];
		a.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += arrA[j];
			a.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		int sum = arrB[i];
		b.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += arrB[j];
			b.push_back(sum);
		}
	}

	sort(b.begin(), b.end());
	long long ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int k = t - a[i];
		int e = upper_bound(b.begin(), b.end(), k) - b.begin();
		int s = lower_bound(b.begin(), b.end(), k) - b.begin();

		ans += (e - s);
	}
	cout << ans;

}