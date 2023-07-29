#include <iostream>
#include <string>
using namespace std;
int main() {
	int k = 964;
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i < 100) cnt++;
		else {
			if ((i % 100) / 10 - (i % 100) % 10 == (i / 100) - (i % 100) / 10) {
				cnt++;
			}
		}
	}
	cout << cnt;
}