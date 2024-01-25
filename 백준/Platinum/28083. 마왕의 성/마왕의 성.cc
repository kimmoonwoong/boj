#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define pll pair<ll, ll>
using namespace std;


pll parent[1001][1001];
ll c[1001][1001];
ll h[1001][1001];
ll ans[1001][1001];
bool visi[1001][1001];
int next_x[4] = { 1, -1, 0, 0 };
int next_y[4] = { 0, 0, 1, -1 };
pll Find(int x, int y) {
	if (parent[x][y].first == -1 && parent[x][y].second == -1) return { x, y };
	return parent[x][y] = Find(parent[x][y].first, parent[x][y].second);
}

void Union(pll x, pll y) {
	x = Find(x.first, x.second);
	y = Find(y.first, y.second);

	if (x == y) return;

	parent[y.first][y.second] = x;
	c[x.first][x.second] += c[y.first][y.second];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;

	map<int, vector<pll>> mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> h[i][j];
			mp[h[i][j]].push_back({ i, j });
			parent[i][j] = { -1, -1 };
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> c[i][j];

	for (auto now : mp) {
		for (pll k : now.second) {
			visi[k.first][k.second] = true;
			for (int i = 0; i < 4; i++) {
				int nextx = k.first + next_x[i];
				int nexty = k.second + next_y[i];
				
				if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
				if (h[nextx][nexty] > h[k.first][k.second]) continue;
				if (visi[nextx][nexty]) continue;

				Union(k, { nextx, nexty });
			}
		}
		for (pll k : now.second) {
			visi[k.first][k.second] = false;
			pll ks = Find(k.first, k.second);
			ans[k.first][k.second] = c[ks.first][ks.second];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}