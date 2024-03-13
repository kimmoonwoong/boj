#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct XY {
	int x, y, cnt;
};
int map[1001][1001];
bool visi[1001][1001];

int next_x_s[6] = { 1, 1, 0, 0, -1 ,-1 };
int next_y_s[6] = { -1, 0, 1, -1, -1, 0 };

int next_x_e[6] = {1, 1, 0, 0, -1, -1};
int next_y_e[6] = {0, 1, -1, 1, 0, 1};
int n, m;
int BFS() {
	queue<XY> q;
	q.push({ 0, 0, 0 });

	visi[0][0] = true;

	while (!q.empty()) {
		XY now = q.front();
		q.pop();
		if (now.x == n - 1 && now.y == m - 1) return now.cnt;

		for (int i = 0; i < 6; i++) {
			int nextx = now.x + (now.x % 2 == 0 ? next_x_s[i] : next_x_e[i]);
			int nexty = now.y + (now.x % 2 == 0 ? next_y_s[i] : next_y_e[i]);
			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
			if (visi[nextx][nexty]) continue;
			if (map[nextx][nexty]) continue;
			

			visi[nextx][nexty] = true;
			q.push({ nextx, nexty, now.cnt + 1 });
		}
	}
	return -1;
}
int main() {
	int k; cin >> n >> m >> k;
	
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		map[x][y] = 1;
	}
	cout << BFS();
}