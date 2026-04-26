#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int ans[10001];
bool visited[10001];

int BFS(const vector<vector<int>>& arr, int idx) {
    queue<int> q;
    memset(visited, false, sizeof(visited));

    visited[idx] = true;
    q.push(idx);

    int cnt = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : arr[now]) {
            if (visited[next]) continue;

            visited[next] = true;
            q.push(next);
            cnt++;
        }
    }

    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> arr(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        arr[b].push_back(a); // 역방향
    }

    int maxs = 0;

    for (int i = 1; i <= n; i++) {
        ans[i] = BFS(arr, i);
        maxs = max(maxs, ans[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == maxs)
            cout << i << " ";
    }
}