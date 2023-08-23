#include<iostream>
#include <string>
#include <queue>
using namespace std;
long long int arrA[100001];
long long int arrB[100001];
double arrK[100001];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arrA[i];
	for (int i = 0; i < n; i++) cin >> arrB[i];
	for (int i = 0; i < n; i++) cin >> arrK[i];
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		int k = int(arrK[i] * 10);
		if (k >= 10) {
			ans += (arrA[i] * k) / 10 - arrB[i];
		}
		else {
			ans += arrA[i] - ((arrB[i] * k) / 10);
		}
	}
	cout << ans;
}
