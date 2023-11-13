#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define ll long long
using namespace std;

struct Node {
    int a;
    int b;
    int w;
};
int parent[1001];

bool cmp(Node o1, Node o2) {
    return o1.w < o2.w;
}

int f(int x) {
    if (parent[x] == x) return x;
    return parent[x] = f(parent[x]);
}
void u(int x, int y) {
    x = f(x), y = f(y);
    parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    vector<Node> edge(m);
    vector<int> yny(k);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < k; i++) cin >> yny[i];

    for (int i = 1; i < k; i++) u(yny[0], yny[i]);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[i] = { a, b, c };
    }
    sort(edge.begin(), edge.end(), cmp);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (f(edge[i].a) != f(edge[i].b)) ans += edge[i].w, u(edge[i].a, edge[i].b);
    }
    cout << ans;
}