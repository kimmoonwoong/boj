#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int arr[10];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 10; i++) 
		cin >> arr[i];
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		if (sum + arr[i] > 100) {
			if (abs((sum + arr[i]) - 100) < abs(100 - sum)) {
				sum += arr[i];
				break;
			}
			if (abs((sum + arr[i]) - 100) == abs(100 - sum)) {
				sum += arr[i];
				break;
			}
			break;
		}
		else sum += arr[i];
	}
	cout << sum;

	return 0;
}