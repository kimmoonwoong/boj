#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int visited[101];
vector<vector<int>> list(101);
int bfs(int start) {
	bool visited[101] = { 0, };
	int index[101] = { 0, };
	queue<int> queue;
	queue.push(start);
	visited[start] = true;
	int sum = 0;
	while (!queue.empty()) {
		int now = queue.front(); queue.pop();

		for (auto next : list[now]) {
			if (visited[next]) continue;

			visited[next] = true;
			sum += index[now] + 1;
			index[next] += index[now] + 1;
			queue.push(next);
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;

	
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	int ans = 0;
	int val = 20000000;
	for (int i = 1; i <= n; i++) {
		int k = bfs(i);
		if (k < val) {
			ans = i;
			val = k;
		}
	}
	cout << ans;
	return 0;
}	