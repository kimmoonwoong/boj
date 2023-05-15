#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

long long n, p, q;
map<long long, long long> mapset;
long long solve(long long n) {
	if (n == 0) return 1;
	if (mapset[n] != 0) return mapset[n];
	
	return mapset[n] = solve(ceil(n / p)) + solve(ceil(n / q));
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> p >> q;
	long long ans = solve(n);
	cout << ans;
	return 0;
}