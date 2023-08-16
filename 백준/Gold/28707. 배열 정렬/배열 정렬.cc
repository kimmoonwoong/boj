#include<iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
using namespace std;


int main(void)
{
	int n; cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int m; cin >> m;
	vector<tuple<int, int, int>> marr(m);

	for (int i = 0; i < m; i++) {
		int l, r, c; cin >> l >> r >> c;
		l--, r--;
		marr[i] = make_tuple(l, r, c);
	}
	set < vector<int>> visited;
	priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;
	q.push({ 0, arr });
	while (!q.empty()) {
		pair<int, vector<int>> now = q.top();
		q.pop();

		if (visited.count(now.second)) continue;
		visited.insert(now.second);

		if (std::is_sorted(now.second.begin(), now.second.end())) {
			cout << now.first;
			return 0;
		}

		for (tuple<int, int, int> ms : marr) {
			auto newarr = now.second;
			swap(newarr[get<0>(ms)], newarr[get<1>(ms)]);

			q.push({ now.first + get<2>(ms), newarr });
		}
	}
	cout << -1;
}