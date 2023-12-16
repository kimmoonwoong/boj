#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int *minTree;
int* maxTree;
int arr[100001];
int INF = 1e9;
int mininit(int start, int end, int node) {
    if (start == end) return minTree[node] = arr[start];
    int mid = (start + end) / 2;
    return minTree[node] = min(mininit(start, mid, node * 2), mininit(mid + 1, end, node * 2 + 1));
}

int minquery(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return INF;
    if (left <= start && right >= end) return minTree[node];
    int mid = (start + end) / 2;
    return min(minquery(start, mid, node * 2, left, right), minquery(mid + 1, end, node * 2 + 1, left, right));
}

int maxinit(int start, int end, int node) {
    if (start == end) return maxTree[node] = arr[start];
    int mid = (start + end) / 2;
    return maxTree[node] = max(maxinit(start, mid, node * 2), maxinit(mid + 1, end, node * 2 + 1));
}

int maxquery(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return -INF;
    if (left <= start && right >= end) return maxTree[node];
    int mid = (start + end) / 2;
    return max(maxquery(start, mid, node * 2, left, right), maxquery(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> arr[i];

    minTree = new int[n * 4];
    maxTree = new int[n * 4];
    fill(minTree, minTree + (n * 4), INF);
    fill(maxTree, maxTree + (n * 4), 0);
    mininit(0, n - 1, 1);
    maxinit(0, n - 1, 1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << minquery(0, n - 1, 1, a - 1, b - 1) << " " << maxquery(0, n - 1, 1, a - 1, b - 1) << "\n";
    }
    return 0;
}