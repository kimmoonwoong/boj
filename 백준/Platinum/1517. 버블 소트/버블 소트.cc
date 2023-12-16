#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define ll long long
using namespace std;
int INF = 1e9;
ll *tree;

void update(int start, int end, int node, int idx) {
    if (start == end) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(start, mid, node * 2, idx);
    else update(mid + 1, end, node * 2 + 1, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pii> arr(n + 1);
    tree = new long long[n * 4 + 1];
    fill(tree, tree + (n * 4 + 1), 0);
    arr[0] = { -INF, 0 };
    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        arr[i] = { val, i };
    }

    sort(arr.begin(), arr.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (long long)sum(1, n, 1, arr[i].second + 1, n);
        update(1, n, 1, arr[i].second);
    }
    cout << ans;
    return 0;
}