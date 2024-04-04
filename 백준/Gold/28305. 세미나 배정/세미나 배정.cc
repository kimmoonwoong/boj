#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t;
vector<int> arr;

bool Bin(int x) {
	vector<int> check(n);

	for (int i = 0; i < n; i++) {
		
		if (i < x) {
			check[i] = max(t, arr[i]);
			continue;
		}
		if (check[i - x] + 1 > arr[i]) return false;
		else check[i] = max(check[i - x] + t, arr[i]);
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);    
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end());
	int l = 0, r = n;
	while (l + 1< r) {
		int mid = (l + r) / 2;
		if (Bin(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r;
}