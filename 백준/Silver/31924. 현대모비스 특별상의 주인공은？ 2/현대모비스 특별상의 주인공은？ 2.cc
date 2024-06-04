#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
#define pii pair<int, int>
using namespace std;

string map[100];
int n;
char mobis[5] = { 'M', 'O', 'B', 'I', 'S' };

int next_x[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int next_y[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };

bool DFS(int x, int y, int cnt, int k) {
	int nextx = x + next_x[k];
	int nexty = y + next_y[k];

	if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) 
		return false;
	if (map[nextx][nexty] == mobis[cnt]) {
		if (cnt >= 4)
			return true;
		else
			return DFS(nextx, nexty, cnt + 1, k);
	}
	else
		return false;
}

void solve() {
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'M') {
				for (int k = 0; k < 8; k++) {
					if (DFS(i, j, 1, k))
						ans++;
				}
			}
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
}