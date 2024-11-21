#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <tuple>
#define pii pair<int, int>
#define ll long long
using namespace std;

ll maps[101][101];
map<pii, pii> mp;
int n, m, t;
ll dist[101][101][101];

int next_x[4] = { 1, -1, 0, 0 };
int next_y[4] = { 0, 0, 1, -1 };

ll INF = 1e18;

void Dekkers() {
    priority_queue<tuple<ll, int, pair<int, int>>, vector<tuple<ll, int, pair<int, int>> >, greater<tuple<ll, int, pair<int, int>> >> pq;

    pq.push({ 0,0,{0, 0} });

    for (int i = 0; i <= t; i++) dist[i][0][0] = 0;

    while (!pq.empty()) {
        tuple<ll, int, pair<int, int>> tp = pq.top();
        auto [d, t1, point] = tp;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nextx = point.first + next_x[i];
            int nexty = point.second + next_y[i];


            if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m)
                continue;
            
            if (dist[t1][nextx][nexty] > maps[nextx][nexty] + d) {
                dist[t1][nextx][nexty] = maps[nextx][nexty] + d;
                pq.push({ dist[t1][nextx][nexty] , t1, {nextx, nexty} });
            }
        }

        if (mp.count(point)) {
            if (t1 >= t)
                continue;
            pii teleport = mp[point];

            if (dist[t1 + 1][teleport.first][teleport.second] > d) {
                dist[t1 + 1][teleport.first][teleport.second] = d;
                pq.push({ d , t1 + 1, teleport });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k, q; cin >> n >> m >> k >> t >> q;

    fill_n(&dist[0][0][0], 101 * 101 * 101, INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--; y1--; y2--;
        mp[{x1, y1}] = { x2, y2 };
    }

    Dekkers();

    for (int i = 0; i < q; i++) {
        int p, x, y; cin >> p >> x >> y;
        x--; y--;
        bool check = false;
        for (int i = 0; i <= t; i++) {
            if (dist[i][x][y] == INF)
                continue;
            if (p >= dist[i][x][y]) {
                cout << 1 << "\n";
                check = true;
                break;
            }
        }

        if (!check)
            cout << 0 << "\n";
    }
}