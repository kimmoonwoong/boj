#include <iostream>
#include <algorithm>
using namespace std;
int parent[100001];
int color[100001];

int Find(int x) {
	if (!parent[x]) return x;

	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[x] = y;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	
	for (int i = 0; i < q; i++) {
		int a, b, x; cin >> a >> b >> x;
		int cur = a;
		while (Find(cur) <= b) {
			color[Find(cur)] = x;
			Union(cur, Find(cur) + 1);
			cur = Find(cur);
		}
	}
	for (int i = 1; i <= n; i++) cout << color[i] << " ";
}