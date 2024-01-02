#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<double, double>
#define ll long long
using namespace std;

ll* tree;
ll arr[100001];
ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
ll sum(int start, int end, int node, int left, int right) {
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
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;

	for (int i = 0; i < n; i++) cin >> arr[i];

	tree = new ll[n * 4 + 1];

	init(0, n - 1, 1);

	for (int i = 0; i < q; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		x--, y--, a--;
		if (x > y) cout << sum(0, n - 1, 1, y, x) << "\n";
		else cout << sum(0, n - 1, 1, x, y) << "\n";
		
		ll diff = b - arr[a];
		arr[a] = b;
		update(0, n - 1, 1, a, diff);
	}
	return 0;
}