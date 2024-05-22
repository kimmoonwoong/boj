#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++) {
		int d; cin >> d;
		pq.push(d);
	}
	vector<int> ans;
	int y = 0;
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();

		y = (int)floor(y / 2) + now;
		ans.push_back(y);

		if (now - m <= k) continue;
		else {
			pq.push(now - m);
		}
	}

	cout << ans.size() << "\n";
	for (int cu : ans) cout << cu << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
}