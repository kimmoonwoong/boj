#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define pii pair<int, int>
#define ll long long
using namespace std;

int next_x[4] = { 1, -1, 0, 0 };
int next_y[4] = { 0, 0, 1, -1 };
int n;
bool checks[51][51];
int ans[51][51];
bool visi[51][51];
bool check(int cnt) {
    for (int i = 1; i <= n; i++) if (!checks[cnt][i]) return false;
    return true;
}
void DFS(pii now, vector<vector<int>> map, int cnt) {
    if (cnt == n - 1) {
        if (check(cnt)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
            exit(0);
        }
    }
    else if (cnt >= n) return;

    if (check(cnt)) {
        for (int i = 0; i < 4; i++) {
            int nextx = now.first + next_x[i];
            int nexty = now.second + next_y[i];
            if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) continue;
            if (visi[nextx][nexty]) continue;

            visi[nextx][nexty] = true;
            ans[nextx][nexty] = cnt + 2;
            checks[cnt + 1][map[nextx][nexty]] = true;
            DFS({ nextx, nexty }, map, cnt + 1);
            visi[nextx][nexty] = false;
            ans[nextx][nexty] = 0;
            checks[cnt + 1][map[nextx][nexty]] = false;
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            int nextx = now.first + next_x[i];
            int nexty = now.second + next_y[i];
            if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) continue;
            if (visi[nextx][nexty]) continue;
            if (checks[cnt][map[nextx][nexty]]) continue;
            visi[nextx][nexty] = true;
            checks[cnt][map[nextx][nexty]] = true;
            ans[nextx][nexty] = cnt + 1;
            DFS({ nextx, nexty }, map, cnt);
            visi[nextx][nexty] = false;
            checks[cnt + 1][map[nextx][nexty]] = false;
            ans[nextx][nexty] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    visi[0][0] = true;
    checks[0][map[0][0]] = true;
    ans[0][0] = 1;
    DFS({ 0, 0 }, map, 0);
    
}