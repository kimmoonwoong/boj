#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

void solve() {
	int n; string s; cin >> n >> s;
	map<char, int> mp;
	string cur = "";
	int cnt = 0;
	for (char c : s) {
		if (!mp.count(c)) {
			cur += c;
			mp[c]++;
		}
		else
			cnt++;
	}
	cnt += 4;
	cur += to_string(cnt);
	int k = 1906 + n;
	string ans = to_string(k) + cur;

	cout << "smupc_";
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
}