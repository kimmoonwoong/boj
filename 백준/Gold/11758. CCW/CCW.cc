#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int curx = 0, cury = 0;
	pair<int, int> arr[3];
	for (int i = 0; i < 3; i++) {
		int x, y; cin >> x >> y;
		if (i == 0) curx = x, cury = y;
		else {
			arr[i] = make_pair(curx - x, cury - y);
			curx = x, cury = y;
		}
	}
	int k = (arr[1].first * arr[2].second) - (arr[1].second * arr[2].first);
	if (k < 0) cout << -1;
	else if (k > 0) cout << 1;
	else cout << 0;
}
