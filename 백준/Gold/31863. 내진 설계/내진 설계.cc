#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define ll long long
#define pii pair<int, int>
using namespace std;

struct Node {
	int x, y;
};
int next_x[4] = { 1, -1, 0, 0 };
int next_y[4] = { 0, 0, 1, -1 };

int n, m, ans1, ans2;
map<pii, int> mp;


void BFS(vector<string> map, pii s) {
	queue<Node> q;
	vector<vector<bool>> visi(n, vector<bool>(m));
	for (int i = 0; i < 4; i++) {
		int nextx = s.first + next_x[i];
		int nexty = s.second + next_y[i];

		if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
		if (map[nextx][nexty] == '|') continue;
		if (map[nextx][nexty] == '#') {
			mp[{nextx, nexty}]--;
		}
		if (map[nextx][nexty] == '*') {
			q.push({ nextx, nexty });
			visi[nextx][nexty] = true;
			ans1--;
			ans2++;
		}

		nextx = nextx + next_x[i];
		nexty = nexty + next_y[i];

		if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
		if (map[nextx][nexty] == '|') continue;
		if (map[nextx][nexty] == '#') {
			mp[{nextx, nexty}]--;
		}
		if (map[nextx][nexty] == '*') {
			q.push({ nextx, nexty });
			visi[nextx][nexty] = true;
			ans1--;
			ans2++;
		}
	}

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextx = now.x + next_x[i];
			int nexty = now.y + next_y[i];

			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
			if (visi[nextx][nexty]) continue;
			if (map[nextx][nexty] == '|') continue;
			
			if (map[nextx][nexty] == '#') {
				mp[{nextx, nexty}]--;
				if (mp[{nextx, nexty}] == 0) {
					visi[nextx][nexty] = true;
					q.push({ nextx, nexty });
					ans1--;
					ans2++;
				}
			}
			if (map[nextx][nexty] == '*') {
				visi[nextx][nexty] = true;
				q.push({ nextx, nexty });
				ans1--;
				ans2++;
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	vector<string> map(n);
	pii s;
	for (int i = 0; i < n; i++) {
		cin >> map[i];

		for (int j = 0; j < m; j++) {
			if (map[i][j] == '@') s = { i, j };
			else if (map[i][j] == '#') mp[{i, j}] = 2;

			if (map[i][j] == '*' || map[i][j] == '#') ans1++;
		}
	}

	BFS(map, s);
	cout << ans2 << " " << ans1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
}