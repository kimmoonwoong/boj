#include <iostream>
#include <algorithm>
using namespace std;
int parent[100001];
long long cnt[100001];
int mod = 1e9;
struct Edge {
    int u;
    int v;
    long long w;
};
Edge arr[100001];
bool cmp(Edge o1, Edge o2) {
    return o1.w > o2.w;
}

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    
        parent[x] = y;
        cnt[y] += cnt[x];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] = 1;
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[i] = { a, b, c };
        sum += c;
    }
    
    sort(arr, arr + m, cmp);
    long long ans = 0;
    
    for (int i = 0; i < m; i++) {
        int u = Find(arr[i].u), v = Find(arr[i].v);
        if (u != v) {
            ans += (((cnt[u] * cnt[v]) % mod) * sum) % mod;
            ans %= mod;
            Union(u, v);
        }
        sum -= arr[i].w;
    }
    cout << ans;
}