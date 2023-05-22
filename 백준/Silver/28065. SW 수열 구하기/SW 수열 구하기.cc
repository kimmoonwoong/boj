#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;


bool desc(long long a, long long b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	cout << n << " ";
	int k = n - 1;
	int m = n;
	for (int i = 1; i < n; i++) {
		if (i % 2 != 0) {
			cout << m - k << " ";
			m -= k;
			k--;
		}
		else {
			cout << m + k << " ";
			m += k;
			k--;
		}
	}
	return 0;
}	