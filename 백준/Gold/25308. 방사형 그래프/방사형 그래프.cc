#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define pii pair<double, double>
using namespace std;
const double pi = 3.141592;

bool ccw(pii dot1, pii dot2, pii dot3) {
	double k = (dot2.first - dot1.first) * (dot3.second - dot1.second) - (dot3.first - dot1.first) * (dot2.second - dot1.second);
	if (k < 0) return true;
	else return false;
}

bool check(vector<int> arrs) {
	vector<pii> now(8);
	double k = sin(45.0 * pi / 180);
	now[0] = { 0, arrs[0] };
	now[1] = { k * arrs[1], k * arrs[1] };
	now[2] = { arrs[2], 0 };
	now[3] = { k * arrs[3], -k * arrs[3] };
	now[4] = { 0, -arrs[4] };
	now[5] = { -k * arrs[5], -k * arrs[5] };
	now[6] = { -arrs[6], 0 };
	now[7] = { -k * arrs[7], k * arrs[7] };
	bool checks = false;
	for (int i = 0; i < 8; i++) {
		if (!ccw(now[i], now[(i + 1) % 8], now[(i + 2) % 8])) checks = true;
	}
	return checks;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	vector<int> arr(8);
	vector<int> idx(8);
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		idx[i] = i;
	}
	int ans = 0;
	do {
		vector<int> checkarr(8);

		for (int i = 0; i < 8; i++) checkarr[i] = arr[idx[i]];

		if (!check(checkarr)) ans++;
	} while (next_permutation(idx.begin(), idx.end()));

	cout << ans;
	return 0;
}