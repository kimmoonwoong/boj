#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	long long n, a, b; cin >> n >> a >> b;
	if (gcd(a, b) != 1) {
		cout << "No";
		return 0;
	}
	else {
		cout << "Yes" << "\n";
		for (int i = 0; i < 2 * n; i += 2) {
			cout << a + i * b << " " << a + (i + 1) * b << "\n";
		}
	}

	return 0;
}