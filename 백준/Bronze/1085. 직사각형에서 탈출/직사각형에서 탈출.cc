#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int x, y, w, h; cin >> x >> y >> w >> h;

	cout << min({ x, y, w - x, h - y });
	return 0;
}