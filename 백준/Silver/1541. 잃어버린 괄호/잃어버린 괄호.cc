#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	string num;
	int ans = 0;
	bool isCheck = false;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '-' || s[i] == '+' || i == s.size()) {
			if (isCheck) ans -= stoi(num);
			else ans += stoi(num);
			num = "";
		}
		else {
			num += s[i];
		}
		if (s[i] == '-') {
			isCheck = true;
		}
	}
	cout << ans;
}