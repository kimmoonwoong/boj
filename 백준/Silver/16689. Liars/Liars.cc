#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = n; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] <= i && i <= b[j])
				cnt++;
		}

		if (i == cnt)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;


}