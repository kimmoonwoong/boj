#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define pii pair<ll, ll>
#define ll long long
using namespace std;
ll INF = LLONG_MAX;
vector<ll> Dekkers(pii s, vector<vector<pii>> list) {
	priority_queue<pii> pq;
	vector<ll> w(list.size(), INF);
	pq.push(s);
	w[s.second] = 0;

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();
		if (w[now.second] < -now.first) continue;

		for (pii next : list[now.second]) {
			ll dist = -now.first + next.second;
			if (w[next.first] > dist) {
				w[next.first] = dist;
				pq.push({ -dist, next.first });
			}
		}
	}
	return w;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, a, b; cin >> n >> m >> a >> b;
	vector<vector<pii>> list(n + 1);

	for (int i = 0; i < m; i++) {
		int a_i, b_i; ll c; cin >> a_i >> b_i >> c;
		list[a_i].push_back({ b_i, c });
		list[b_i].push_back({ a_i, c });
	}

	vector<ll> a_w = Dekkers({ 0, a }, list);
	ll mins = a_w[b];
	vector<ll> b_w = Dekkers({ 0, b }, list);
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (a_w[i] + b_w[i] == mins) ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int k : ans) cout << k << " ";
}