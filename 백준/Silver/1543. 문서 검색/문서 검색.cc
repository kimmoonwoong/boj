#include <iostream>
#include <string>
#define pii pair<double, double>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; getline(cin, s);
	string check; getline(cin, check);
	if (s.length() < check.length()) {
		cout << 0; 
		return 0;
	}

	int i = 0;
	int ans = 0;
	while (true) {
		if (i >= s.length()) break;
		if (s.substr(i, check.length()) == check) {
			ans++;
			i += check.length();
		}
		else i++;
	}
	cout << ans;
	return 0;
}