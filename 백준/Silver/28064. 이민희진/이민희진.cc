#include <iostream>
#include<cstring>
#include <string>
#include <numeric>
#include <vector>
using namespace std;
string arr[100];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				ans++;	
				continue;
			}
			int size = arr[i].length() < arr[j].length() ? arr[i].length() : arr[j].length();
			for (int k = 1; k <= size; k++) {
				if (arr[i].substr(arr[i].length() - k) == arr[j].substr(0, k)) {
					ans++;
					break;
				}
				if (arr[i].substr(0, k) == arr[j].substr(arr[j].length() - k)) {
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}	