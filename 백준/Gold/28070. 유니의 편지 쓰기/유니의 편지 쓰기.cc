#include <iostream>
#include<cstring>
#include <string>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> arr(1400001);
	for (int i = 0; i < n; i++) {
		string start, end; cin >> start >> end;
		int s = stoi(start.substr(0, 4)) * 12 + stoi(start.substr(5));
		int e = stoi(end.substr(0, 4)) * 12 + stoi(end.substr(5));
		arr[s]++;
		arr[e + 1]--;
	}

	partial_sum(arr.begin(), arr.end(), arr.begin());
	
	int ans = 0;
	int count = 0;
	
	for (int i = 0; i < arr.size(); i++) {
		if (count < arr[i]) {
			count = arr[i];
			ans = i;
		}
	}
	if (ans % 12 == 0) cout << ans / 12 - 1<< "-12";
	else if (ans % 12 < 10) cout << ans / 12 << "-0" << ans % 12;
	else cout << ans / 12 << "-" << ans % 12;

	return 0;
}	