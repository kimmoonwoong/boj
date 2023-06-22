#include <iostream>
#include <string>
using namespace std;
int arr[200001][26];
int main() {
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		arr[i][s[i] - 'a'] = 1;
	}
	for (int i = 1; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			arr[i][j] += arr[i - 1][j];
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