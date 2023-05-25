#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

set<int> checkset;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while (T) {
		checkset.clear();
		int n; cin >> n;
		vector<int> arr(n + 1);
		vector<int> startindex(n + 1);
		vector<int> endindex(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (startindex[arr[i]] == 0) startindex[arr[i]] = i;
			else endindex[arr[i]] = i;
		}
		bool isCheck = false;
		for (int i = 1; i <= n; i++) {
			if (endindex[arr[i]] == 0) {
				if (!checkset.empty()) {
					auto it = checkset.begin();
					if (*it < arr[i]) {
						cout << "No" << "\n";
						isCheck = true;
						break;
					}
				}
				continue;
			}
			if (startindex[arr[i]] == i) checkset.insert(arr[i]);
			auto it = checkset.begin();
			if (*it < arr[i]) {
				cout << "No" << "\n";
				isCheck = true;
				break;
			}
			
			if (endindex[arr[i]] == i) {
				checkset.erase(arr[i]);
			}
		}
		if (!isCheck) cout << "Yes\n";
		T--;
	}
	return 0;
}	