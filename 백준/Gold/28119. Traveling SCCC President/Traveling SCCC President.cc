#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};
const int n = 2001;
vector<pair<int, int>> arr[n];
bool visited[2001];
int Prim(pair<int, int> start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>q;
	q.push(start);
	int cnt = 0;
	while (!q.empty()) {
		pair<int, int> now = q.top();
		q.pop();
		if (visited[now.first]) continue;
		visited[now.first] = true;
		cnt += now.second;

		for (auto next : arr[now.first]) {
			if(!visited[next.first]) q.push(next);
		}
	}
	return cnt;
}
int main() {
	int n, m, s; cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		arr[u].push_back({v, w});
		arr[v].push_back({u, w});
	}

	for (int i = 0; i < n; i++)
	{
		int k; cin >> k;
	}

	int ans = Prim({s, 0});
	cout << ans;
}
