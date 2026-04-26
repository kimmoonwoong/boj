#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t; cin >> n >> t;

	vector<int> arr(n);
	vector<int> sortArr;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < t; i++) {
		sortArr.push_back(arr[i]);
	}

	sort(sortArr.begin(), sortArr.end());

	for (int i = 0; i < t; i++) {
		cout << sortArr[i] << " ";
	}
	for (int i = t; i < n; i++) {
		cout << arr[i] << " ";
	}

}