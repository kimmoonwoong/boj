#include <iostream>
#include <vector>
#include <cmath>
#define pii pair<int, int>
using namespace std;

long long arr[1000001];
long long *tree;

long long init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, long long dif) {
    if (idx > end || idx < start) return;

    tree[node] += dif;
    if (start == end) return;
    int mid = (start + end) / 2;

    update(start, mid, node * 2, idx, dif);
    update(mid + 1, end, node * 2 + 1, idx, dif);
}

int main() {
    int n, m, k; cin >> n >> m >> k;

    for (int i = 0; i < n; i++) cin >> arr[i];
    tree = new long long[4 * n];
    init(0, n - 1, 1);

    for (int i = 0; i < m + k; i++) {
        int a, b; long long c; cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(0, n - 1, 1, b - 1, diff);
        }
        else cout << sum(0, n - 1, 1, b - 1, c - 1) << "\n";
    }
}