#include <iostream>
#include <queue>
using namespace std;

int arr[1001];
bool visited[1001];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0] = true;
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
;		if (now.first == n - 1) {
			cout << now.second;
			return 0;
		}

		for (int i = 1; i <= arr[now.first]; i++) {
			if (now.first + i >= n || visited[now.first + i]) continue;
			visited[now.first + i] = true;
			q.push({ now.first + i, now.second + 1 });
		}
	}
	cout << -1;
}