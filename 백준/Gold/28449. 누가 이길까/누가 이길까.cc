#include<iostream>
#include <algorithm>
using namespace std;

int hiarr[100001];
int arcarr[100001];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> hiarr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arcarr[i];
	}

	sort(hiarr, hiarr + n);
	sort(arcarr, arcarr + m);
	long long hiwin = 0, arcwin = 0, tie = 0;
	for (int i = 0; i < n; i++) {
		long long k = upper_bound(arcarr, arcarr + m, hiarr[i]) - arcarr;
		long long p = lower_bound(arcarr, arcarr + m, hiarr[i]) - arcarr;

		if (k == p) {
			hiwin += k;
			arcwin += (m - k);
		}
		else {
			
			tie += (k - p);
			hiwin += (p);
			arcwin += (m - k);
		}
	}

	cout << hiwin << " " << arcwin << " " << tie;
}