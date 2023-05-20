#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long a[200001];
long long b[200001];

bool desc(long long a, long long b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	sort(a, a + n, desc);
	sort(b, b + m);
	int size = n < m ? n : m;
	long long ans = 0;
	for (int i = 0; i < size; i++) ans += (a[i] - b[i]) > 0 ? (a[i] - b[i]) : 0;
	cout << ans;
	return 0;
}	