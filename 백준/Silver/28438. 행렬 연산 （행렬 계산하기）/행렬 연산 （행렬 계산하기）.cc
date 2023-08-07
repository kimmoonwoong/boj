#include <iostream>
#include <algorithm>
using namespace std;
int row[500001];
int col[500001];
int main() {
	int n, m, q; cin >> n >> m >> q;

	for (int i = 0; i < q; i++) {
		int k, x, v; cin >> k >> x >> v;
		if (k == 1) row[x] += v;
		else col[x] += v;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << row[i] + col[j] << " ";
		}
		cout << "\n";
	}
}