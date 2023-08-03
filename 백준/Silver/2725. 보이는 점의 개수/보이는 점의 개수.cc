#include <iostream>
#include <vector>
using namespace std;
int arr[1001];

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	arr[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1) cnt++;
		}
		arr[i] += (cnt * 2);
		arr[i] += arr[i - 1];
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << arr[n] << "\n";
	}
}