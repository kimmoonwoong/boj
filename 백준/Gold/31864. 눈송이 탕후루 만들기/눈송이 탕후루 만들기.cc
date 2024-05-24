#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define pii pair<int, int>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void solve() {
	int n, m; cin >> n >> m;
	map<pii, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		int g = x && y ? gcd(abs(x), abs(y)) : max(abs(x), abs(y));
		mp[{x / g, y / g}].push_back(x ? abs(x) : abs(y));
	}
    
    for (auto iter = mp.begin() ; iter !=  mp.end(); iter++)
    {
	    auto& v = iter->second;
        sort(v.begin(), v.end());
    }
	
	int ans = 0;

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		int g = x && y ? gcd(abs(x), abs(y)) : max(abs(x), abs(y));
		
		if (mp.count({ x / g, y / g })) {
			auto& v = mp[{ x / g, y / g }];
			int k = upper_bound(v.begin(), v.end(), x ? abs(x) : abs(y)) - v.begin();
			ans = max(ans, k);
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
}