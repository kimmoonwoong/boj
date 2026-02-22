#include <iostream>
using namespace std;
long long arr[1024];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		arr[idx++] = i;
	}
	for (int i = 1; i < 1022; i++) {
		for (int j = 0; j <= 9; j++) {
			if (arr[i] % 10 > j) {
				arr[idx++] = arr[i] * 10 + j;
			}
		}
	}
	int n; cin >> n;

	if (n > 1023)
		cout << -1;
	else
		cout << arr[n - 1];

}