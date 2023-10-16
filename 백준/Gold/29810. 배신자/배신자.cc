#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool visited[200001];
vector<vector<int>> list(200001);
int s;
long long ans = 0;
int check = -1;
long long DFS(int now, int before, int s, bool isCheck) {
    if (isCheck) {
        for (int next : list[now]) {
            if (visited[next]) {
                if (next == s && before != s && check == -1) {
                    check = now;
                    continue;
                }
            }
        }
    }
    long long depth = 1;
    for (int next : list[now]) {
        if (visited[next]) continue;
        visited[next] = true;
        if (now == s && isCheck) {
            ans = max(DFS(next, now, s, isCheck) + 1, ans);
            check = -1;
        }
        else {
            depth += DFS(next, now, s, isCheck);
            ans = max(depth, ans);
        }
    }
    if (now == check) return depth - 1;
    return depth;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    cin >> s;
    visited[s] = true;
    DFS(s, 0,  s, true);
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        DFS(i, 0, i, false);
    }
    if (n == 1) cout << 1;
    else  cout << ans;

}