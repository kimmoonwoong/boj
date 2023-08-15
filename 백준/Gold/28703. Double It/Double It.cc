#include<iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<long long, vector<long long>, greater<long long>> pq;

	int n; cin >> n;
	long long maxs = 0, arrmaxs = 0;

	for (int i = 0; i < n; i++) {
		long long k; cin >> k;

		if (maxs < k) maxs = k;
		pq.push(k);
	}

	arrmaxs = maxs;
	long long ans = 1e12;
	while (pq.top() <= arrmaxs) {
		long long m = pq.top();
		pq.pop();
		ans = min(ans, maxs - m);
		if (m * 2 > maxs) maxs = m * 2;
		pq.push(m * 2);
	}
	cout << ans;
}