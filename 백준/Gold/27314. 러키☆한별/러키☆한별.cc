#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct XY
{
	int x, y, cnt;
};

int n = 0, m = 0;
int next_x[4] = { 1,-1,0,0 };
int next_y[4] = { 0, 0, 1, -1 };

map<pair<int, int>, int> mp;
void BFS(XY start, vector<string> map, vector<vector<int>> &cntmap, bool check) {
	queue<XY> q;
	vector<vector<bool>> visited(n, vector<bool>(m));
	q.push(start);
	visited[start.x][start.y];

	while (!q.empty()) {
		XY now = q.front();
		q.pop();
		if (map[now.x][now.y] == '#') {
			if (check) {
				cntmap[now.x][now.y] = now.cnt;
			}
			else {
				if (cntmap[now.x][now.y] >= now.cnt) mp[{now.x, now.y}]++;
			}
			visited[now.x][now.y] = true;
		}

		for (int i = 0; i < 4; i++) {
			int nextx = now.x + next_x[i];
			int nexty = now.y + next_y[i];

			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
			if (visited[nextx][nexty]) continue;
			if (map[nextx][nexty] == 'X') continue;
			XY next = {nextx, nexty, now.cnt + 1};
			visited[nextx][nexty] = true;
			q.push(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<string> map(n);
	vector<vector<int>> cntmap(n, vector<int>(m));
	vector<XY> people;

	XY han;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'H') {
				han = { i, j , 0};
			}
			else if (map[i][j] == 'P') {
				people.push_back({ i, j , 0});
			}
		}
	}
	BFS(han, map, cntmap, true);
	for (int i = 0; i < people.size(); i++) {
		BFS(people[i], map, cntmap, false);
	}
	int ans = 0;
	for (auto iter : mp) {
		ans = max(ans, iter.second);
	}
	cout << ans;
}