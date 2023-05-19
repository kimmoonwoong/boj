#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int arr[101];
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr,arr + n);
	int arr_gcd = arr[1] - arr[0];
	for (int i = 2; i < n; i++) {
		int dis = arr[i] - arr[i - 1];
		arr_gcd = gcd(dis, arr_gcd);
	}
	ans.push_back(arr_gcd);
	for (int i = 2; i <= sqrt(arr_gcd); i++) {
		if (arr_gcd % i == 0) {
			ans.push_back(i);
			if (i != arr_gcd / i) ans.push_back(arr_gcd / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}	