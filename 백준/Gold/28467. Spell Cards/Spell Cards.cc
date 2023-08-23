#include<iostream>
#include <string>
#include <queue>
using namespace std;
long long arr[401];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}

	long long ans = 0;

	while (true) {
		int mins = 1e9 + 7;
		int idx = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) continue;
			else cnt++;

			if (mins > arr[i]) {
				mins = arr[i];
				idx = i;
			}
		}
		if (cnt <= 1) break;
		if (idx + 1 >= n) {
			int next_idx = idx - 1;
			while (next_idx >= 0) {
				if (arr[next_idx] != 0) break;
				next_idx--;
			}
			ans += arr[idx] + arr[next_idx];
			arr[next_idx] =  max(arr[next_idx], arr[idx]);
			arr[idx] = 0;
		}
		else if (idx - 1 < 0) {
			int next_idx = idx + 1;
			while (next_idx < n) {
				if (arr[next_idx] != 0) break;
				next_idx++;
			}

			ans += arr[idx] + arr[next_idx];
			arr[next_idx] = max(arr[next_idx], arr[idx]);
			arr[idx] = 0;
		}
		else {
			int left = idx - 1;
			int right = idx + 1;
			while (left >= 0) {
				if (arr[left] != 0)break;
				left--;
			}
			while (right < n) {
				if (arr[right] != 0) break;
				right++;
			}
			if (left < 0) {
				ans += arr[idx] + arr[right];
				arr[right] = max(arr[idx], arr[right]);
				arr[idx] = 0;
			}
			else if (right >= n) {
				ans += arr[idx] + arr[left];
				arr[left] = max(arr[idx], arr[left]);
				arr[idx] = 0;
			}
			else {
				int nextidx = arr[left] < arr[right] ? left : right;
				ans += arr[idx] + arr[nextidx];
				arr[nextidx] = max(arr[idx], arr[nextidx]);
				arr[idx] = 0;
			}
		}
	}
	cout << ans;
}
