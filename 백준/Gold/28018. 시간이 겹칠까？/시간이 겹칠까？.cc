#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> arr(1000001);
	for (int i = 0; i < n; i++) {
		int start, end; cin >> start >> end;
		arr[start]++;
		arr[end + 1]--;
	}
	partial_sum(arr.begin(), arr.end(), arr.begin());
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int k; cin >> k;
		cout << arr[k]<< "\n";
	}
	return 0;
}