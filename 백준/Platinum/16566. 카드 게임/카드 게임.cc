#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int parent[4000001];
vector<int> v;
vector<int> ::iterator it;

int find(int num) {
	if (parent[num] == num) return num;
	else return parent[num] = find(parent[num]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	parent[u] = v;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		parent[i] = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		int idx = find(upper_bound(v.begin(), v.end(), a) - v.begin());
		cout << v[idx] << '\n';
		merge(idx, idx + 1);
	}
}