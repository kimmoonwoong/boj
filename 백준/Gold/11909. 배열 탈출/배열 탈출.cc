#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int next_x[2] = { 1, 0};
int next_y[2] = { 0, 1};

int map[2222][2222];
int INF = 1e9;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	priority_queue<tuple<int, int, int>> pq;
	dist[0][0] = 0;
	pq.push({ 0, 0, 0 });

	while (!pq.empty()) {
		tuple<int, int, int> now = pq.top();
		pq.pop();
		int dis, x, y;
		tie(dis, x, y) = now;
		if (dist[x][y] < -dis) continue;
		int nextx = x, nexty = y;
		if (x == n - 1 && y == n - 1) break;
		else if (x == n - 1) nexty = y + 1;
		else if (y == n - 1) nextx = x + 1;
		else {
			for (int i = 0; i < 2; i++) {
				nextx = x + next_x[i];
				nexty = y + next_y[i];

				if (map[x][y] > map[nextx][nexty]) {
					if (dist[nextx][nexty] > -dis) {
						dist[nextx][nexty] = -dis;
						pq.push({ -dist[nextx][nexty], nextx, nexty });
					}
				}
				else {
					if (dist[nextx][nexty] > (-dis) + map[nextx][nexty] - map[x][y] + 1) {
						dist[nextx][nexty] = (-dis) + map[nextx][nexty] - map[x][y] + 1;
						pq.push({ -dist[nextx][nexty], nextx, nexty });
					}
				}
			}
			continue;
		}

		if (map[x][y] > map[nextx][nexty]) {
			if (dist[nextx][nexty] > -dis) {
				dist[nextx][nexty] = -dis;
				pq.push({ -dist[nextx][nexty], nextx, nexty });
			}
		}
		else {
			if (dist[nextx][nexty] > (-dis) + map[nextx][nexty] - map[x][y] + 1) {
				dist[nextx][nexty] = (-dis) + map[nextx][nexty] - map[x][y] + 1;
				pq.push({ -dist[nextx][nexty], nextx, nexty });
			}
		}

	}

	cout << dist[n - 1][n - 1];
}