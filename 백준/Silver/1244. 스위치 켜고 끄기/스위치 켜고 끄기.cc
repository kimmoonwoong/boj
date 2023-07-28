#include <iostream>
#include <string>
using namespace std;
int arr[101];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int k; cin >> k;
	
	for (int i = 0; i < k; i++) {
		int z, idx; cin >> z >> idx;
		if (z == 1) {
			for (int i = idx; i <= n; i++) {

				if (i % idx == 0) {
					arr[i] = !arr[i];
				}
			}
		}
		else {
			int s = idx, e = idx;
			while (s >= 1 && e <= n) {
				if (arr[s] != arr[e]) break;
				s--, e++;
			}
			for (int i = s + 1; i <= e - 1; i++) {
				arr[i] = !arr[i];
			}
		}

	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
		if (i != 0 && i % 20 == 0) cout << "\n";
	}
}