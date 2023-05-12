#include <iostream>

using namespace std;

int arr[5000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = n;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) ans--;
	}
	
	cout << ans;

	return 0;
}