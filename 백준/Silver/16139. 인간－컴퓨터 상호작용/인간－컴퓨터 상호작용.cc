#include <iostream>
#include <string>
using namespace std;
int arr[200001][26];
int main() {
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		arr[i][s[i] - 'a'] = 1;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j < s.size(); j++) {
			arr[j][i] += arr[j - 1][i];
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		char c;
		int a, b; cin >> c >> a >> b;
		if (a == 0) cout << arr[b][c - 'a'] << "\n";
		else cout << arr[b][c - 'a'] - arr[a - 1][c - 'a'] << "\n";
	}
}