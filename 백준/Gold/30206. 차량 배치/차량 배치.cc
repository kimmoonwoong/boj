#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int mod = 1e9 + 7;
vector<long long> BFS(vector<vector<int>> list) {
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    vector<bool> visited(n + 1);
    vector<long long> arr(n + 1);
    visited[1] = true;
    arr[1] = 1;
    while (!q.empty()) {
        pair<int, long long> now = q.front();
        q.pop();

        for (int next : list[now.first]) {
            if (visited[next]) continue;
            visited[next] = true;
            arr[now.second + 1]++;
            q.push({ next, now.second + 1});
        }
    }

    return arr;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m; cin >> n >> m;
    vector<vector<int>> list(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    vector<long long> arr = BFS(list);
    long long ans = 1;
    for (int i = 1; i <= n;i++) {
        if (arr[i] == 0) break;
        ans *= (arr[i] + 1);
        ans %= mod;
    }
    cout << ans - 1;
}