#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct XY {
    int x, y, cnt;
    
};

struct cmp {
    bool operator()(XY o1, XY o2) {
        return o1.cnt < o2.cnt;
    }
};
int next_x[4] = { 1,-1,0,0 };
int next_y[4] = { 0,0,1,-1 };
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    priority_queue<XY, vector<XY>, cmp> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt; cin >> cnt;
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                pq.push({ i, j, cnt });
            }
            else {
                arr[i][j] = cnt;
            }
        }
    }

    int k; cin >> k;

    for (int i = 0; i < k; i++) {
        XY now = pq.top();
        pq.pop();
        cout << now.x + 1 << " " << now.y + 1 << "\n";
       
        for (int i = 0; i < 4; i++) {
            int nextx = now.x + next_x[i];
            int nexty = now.y + next_y[i];

            if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
            if (arr[nextx][nexty] == -1) continue;

            pq.push({ nextx, nexty, arr[nextx][nexty] });
            arr[nextx][nexty] = -1;
        }
    }
}