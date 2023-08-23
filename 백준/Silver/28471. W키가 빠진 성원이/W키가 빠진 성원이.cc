#include<iostream>
#include <string>
#include <queue>
using namespace std;

string map[2001];
int nextx[7] = { -1, 0, 0, 1, -1, 1, -1 };
int nexty[7] = { 0, -1, 1, 1, -1, -1, 1 };
int n = 0;
int BFS(pair<int, int> start, vector<vector<bool>> visited) {
	queue<pair<int, int>> q;
	q.push(start);
	int ans = 0;
	visited[start.first][start.second] = true;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 7; i++) {
			int next_x = now.first + nextx[i];
			int next_y = now.second + nexty[i];
			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;
			if (visited[next_x][next_y]) continue;
			if (map[next_x][next_y] == '#') continue;
			ans++;
			visited[next_x][next_y] = true;
			q.push({ next_x, next_y });
		}
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	n; cin >> n;
	pair<int, int> start;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < n; j++) if (map[i][j] == 'F') {
			start = { i, j };
		}
	}
	vector < vector < bool>> visited(n, vector<bool>(n));
	int ans = BFS(start, visited);
	cout << ans;
}