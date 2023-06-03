#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int n; cin >> n;

	string s; cin >> s;
	int commend[3] = { 0, };
	int k; cin >> k;
	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i, 1) == "U") commend[0]++;
		else if (s.substr(i, 1) == "R") commend[1]++;
		else commend[2]++;
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int nx, ny; cin >> nx >> ny;
		nx--, ny--;
		if (nx == commend[2] && ny == commend[2]) ans++;
		else {
			int tmp = min(nx, ny);
			if (tmp > commend[2]) nx -= commend[2], ny -= commend[2];
			else nx -= tmp, ny -= tmp;

			if (commend[1] >= nx && commend[0] >= ny) ans++;
		}
	}
	cout << ans;
}	
