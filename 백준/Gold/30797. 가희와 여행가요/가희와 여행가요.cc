#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int parent[200001];

struct Edge {
    int a, b;
    long long c, t;
    bool operator<(const Edge& d) const {
        if (c == d.c) return t < d.t;
        else return c < d.c;
    }
};

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) parent[y] = x;
}

int main() {
    int n, q; cin >> n >> q;
    
    for (int i = 1; i <= n; i++) parent[i] = i;
    vector<Edge> list(q);
    for (int i = 0; i < q; i++) {
        int a, b; long long c, t; cin >> a >> b >> c >> t;
        list[i] = { a, b, c, t };
    }
    
    sort(list.begin(), list.end());
    long long cost = 0, time = 0;
    vector<bool> check(n + 1);
    for (Edge now : list) {
        if (Find(now.a) != Find(now.b)) {
            check[now.a] = true;
            check[now.b] = true;
            cost += now.c;
            time = max(now.t, time);
            Union(now.a, now.b);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << time << " " << cost;
    return 0;
}