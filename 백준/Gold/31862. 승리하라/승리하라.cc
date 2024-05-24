#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define pii pair<int, int>
using namespace std;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> win(n + 1);
	vector<pii> arr;
	for (int i = 0; i < m; i++) {
		int t1, t2, r; cin >> t1 >> t2 >> r;

		if (r == 0) 
			arr.push_back({ t1, t2 });
		else if (r == 1)
			win[t1]++;
		else
			win[t2]++;
	}
	int winmax = 0;
	bool check = false, visitrank = false;

	for (int i = 1; i <= n; i++)
	{
 		if (winmax < win[i]) {
			winmax = win[i];
			visitrank = false;
			check = i == k;
		}
		else if (winmax == win[i]) {
			visitrank = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << arr.size()); i++) {
		int mx = winmax;
		bool ch = check, visi = visitrank;

		for (int j = 0; j < arr.size(); j++) {
			if (i & (1 << j)) {
				win[arr[j].first]++;

				if (win[arr[j].first] > mx)
				{
					mx = win[arr[j].first];
					visi = false;
					ch = arr[j].first == k;
				}
				else if (win[arr[j].first] == mx) {
					visi = true;
				}
			}
			else {
				win[arr[j].second]++;

				if (win[arr[j].second] > mx)
				{
					mx = win[arr[j].second];
					visi = false;
					ch = arr[j].second == k;
				}
				else if (win[arr[j].second] == mx) {
					visi = true;
				}
			}
		}
		if (ch && !visi) ans++;

		for (int j = 0; j < arr.size(); j++) {
			if (i & (1 << j)) {
				win[arr[j].first]--;
			}
			else {
				win[arr[j].second]--;
			}
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
}