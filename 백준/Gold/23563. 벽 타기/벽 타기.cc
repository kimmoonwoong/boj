#include <iostream>
#include <vector>
#include <string>
#include <deque>
#define pii pair<int, int>
#define pl pair<int, pii>
using namespace std;
int INF = 1e9;
int next_x[4] = { 1, -1, 0, 0 };
int next_y[4] = { 0,0,1,-1 };

int n, m;
int map[501][501];

int BFS(pii s, pii e) {
    deque<pl> dq;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[s.first][s.second] = 0;
    dq.push_front({ 0, s });

    while (!dq.empty()) {
        pl now = dq.front();
        dq.pop_front();
        if (now.first > dist[now.second.first][now.second.second]) continue;

        for (int i = 0; i < 4; i++) {
            int nextx = now.second.first + next_x[i];
            int nexty = now.second.second + next_y[i];

            if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
            if (map[nextx][nexty] == -1) continue;

            if (!map[now.second.first][now.second.second] && !map[nextx][nexty]) {
                if (dist[nextx][nexty] > now.first) {
                    dist[nextx][nexty] = now.first;
                    dq.push_front({ now.first, {nextx, nexty} });
                }
            }
            else {
                if (dist[nextx][nexty] > now.first + 1) {
                    dist[nextx][nexty] = now.first + 1;
                    dq.push_back({ now.first + 1, {nextx, nexty} });
                }
            }
        }
    }
    return dist[e.first][e.second];
}

int main() {
    cin >> n >> m;
    vector<pii> wall;
    pii sa, ea;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                map[i][j] = 1;
            }
            else if (s[j] == '#') {
                map[i][j] = -1;
                wall.push_back({ i, j });
            }
            else if (s[j] == 'S') {
                sa = { i, j };
                map[i][j] = 1;
            }
            else {
                ea = { i, j };
                map[i][j] = 1;
            }
        }
    }
    for (pii now : wall) {
        for (int i = 0; i < 4; i++) {
            int nx = now.first + next_x[i];
            int ny = now.second + next_y[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (map[nx][ny] == -1) continue;
            map[nx][ny] = 0;
        }
    }
    cout << BFS(sa, ea);
}