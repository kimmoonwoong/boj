#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int cnt = 1;
	for (int i = 0; i < n * 3; i++) {
		cout << cnt << " ";
		cnt += 1;
		if (cnt > n)
			cnt = 1;
	}
}