#include <iostream>
#include <vector>
#include <time.h>
#define pii pair<int, int>
using namespace std;

int main() {
	int y, m, d; cin >> y >> m >> d;
	struct tm jh;
	struct tm yd;
	jh.tm_year = y - 1900; jh.tm_mon = m - 1; jh.tm_mday = d; jh.tm_hour = 0; jh.tm_min = 0; jh.tm_sec = 0; jh.tm_isdst = 0;
	int yy, ym, yds; cin >> yy >> ym >> yds;
	yd.tm_year = yy - 1900; yd.tm_mon = ym - 1; yd.tm_mday = yds; yd.tm_hour = 0; yd.tm_min = 0; yd.tm_sec = 0; yd.tm_isdst = 0;

	time_t s = mktime(&jh);
	time_t e = mktime(&yd);

	double diff = difftime(e, s);
	int diff_day = diff / (60 * 60 * 24);

	int t, n; cin >> t >> n;
	
	vector<pii> arr(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(t + 1));
	for (int i = 1; i <= n; i++) {
		int k, c, v; cin >> k >> c >> v;
		if (k == 3) arr[i] = { c, v * 30 };
		else arr[i] = { c, v };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j < arr[i].first) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			else {
				dp[i][j] = max(dp[i - 1][j - arr[i].first] + arr[i].second, dp[i - 1][j]);
			}
		}
	}
	cout << abs(diff_day - dp[n][t]);
}