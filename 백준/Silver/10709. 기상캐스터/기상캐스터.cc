#include <iostream>
#include <vector>
#include <string>
using namespace std;
string map[101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		int k = -1;
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'c') k = 0;
			cout << k << " ";
			if(k != -1) k++;
		}
		cout << "\n";
	}
}