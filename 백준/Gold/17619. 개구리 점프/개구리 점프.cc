#include <iostream>
#include <algorithm>
using namespace std;

struct Segment
{
	int x1, x2, idx;

	bool operator < (const Segment& p) const
	{
		if (x1 == p.x1) return p.x2 < x2;
		else return x1 < p.x1;
	}
};

int parent[100001];
Segment arr[100001];

int Find(int x) {
	if (x == parent[x]) return parent[x];

	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		if (x < y) parent[y] = x;
		else parent[x] = y;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> arr[i].x1 >> arr[i].x2 >> y;
		arr[i].idx = i;
		
	}
	sort(arr, arr + n);
	int start = arr[0].x1, end = arr[0].x2;
	int idx = arr[0].idx;
	for (int i = 1; i < n; i++) {
		if (end < arr[i].x1) {
			start = arr[i].x1;
			end = arr[i].x2;
			idx = arr[i].idx;
		}
		if (end < arr[i].x2) {
			end = arr[i].x2;
			Union(idx, arr[i].idx);
			idx = arr[i].idx;
		}

		if (end >= arr[i].x2) {
			Union(idx, arr[i].idx);
		}
	}

	for (int i = 0; i < q; i++) {
		int n1, n2; cin >> n1 >> n2;
		n1--; n2--;
		if (Find(n1) == Find(n2)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}


}