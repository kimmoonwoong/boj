#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

map<string, int> mp;
string arr[101];
int main() {
	int n; cin >> n;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]] = 1;
		if (arr[i] == "?") {
			idx = i;
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (n == 1) {
			cout << s;
			return 0;
		}
		if (idx == 0) {
			if (arr[idx + 1][0] == s[s.size() - 1] && mp.count(s) == 0) {
				cout << s;
				break;
			}
		}
		else if (idx == n - 1) {
			if (arr[idx - 1][arr[idx - 1].size() - 1] == s[0] && mp.count(s) == 0) {
				cout << s;
				break;
			}
		}
		else {
			if (arr[idx - 1][arr[idx - 1].size() - 1] == s[0] && arr[idx + 1][0] == s[s.size() - 1] && mp.count(s) == 0) {
				cout << s;
				break;
			}
		}
	}
}