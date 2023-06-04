#include <iostream>
#include <string>


using namespace std;

int parent[41];


int Find(int x) {
	if (parent[x] == x) return x;

	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		if (x > y) parent[y] = x;
		else parent[x] = y;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (Find(a) != Find(b)) Union(a, b);
	}

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (Find(1) != Find(i)) {
			Union(1, i);
			ans++;
		}
	}
	cout << ans;
}