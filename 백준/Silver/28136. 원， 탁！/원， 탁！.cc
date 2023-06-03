#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int arr[1000001];


int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] >= arr[i + 1]) ans++;
	}
	if (arr[n - 1] >= arr[0]) ans++;
	cout << ans;
}
