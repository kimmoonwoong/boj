#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[101][101];
int n;
int minval = 201;
int maxval = 0;
int next_x[4] = { 1,-1,0,0 };
int next_y[4] = { 0,0,1,-1 };
bool BFS(int value) {
    for (int k = minval; k <= maxval; k++) {
        vector<vector<bool>> visited(n, vector<bool>(n, true));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] >= k && k + value >= map[i][j]) {
                    visited[i][j] = false;
                }

            }
        }
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            if (visited[now.first][now.second]) continue;
            visited[now.first][now.second] = true;
            
            if (now.first == n - 1 && now.second == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nextx = now.first + next_x[i];
                int nexty = now.second + next_y[i];

                if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) continue;

                q.push({ nextx, nexty });
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (minval > map[i][j]) minval = map[i][j];
            if (maxval < map[i][j]) maxval = map[i][j];
        }
    }
    int s = 0, e = maxval - minval;

    while (s <= e) {
        int mid = (s + e) / 2;
        if (BFS(mid)) e = mid - 1;
        else s = mid + 1;
    }

    cout << e + 1;
  
}