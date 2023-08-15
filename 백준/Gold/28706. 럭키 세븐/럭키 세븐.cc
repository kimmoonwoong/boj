#include<iostream>
#include <algorithm>
#include <queue>
using namespace std;

int cal(int d, int v1, char op) {
	return op == '*' ? (d * v1) : (d + v1);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;
		vector < vector <bool> > dp(n + 1, vector <bool>(7));
		dp[0][1] = true;
		for (int i = 1; i <= n; i++) {
			char op1, op2;
			int v1, v2;
			cin >> op1 >> v1 >> op2 >> v2;

			for (int j = 0; j < 7; j++) {
				if (dp[i - 1][j]) {
					dp[i][cal(j, v1, op1) % 7] = true;
					dp[i][cal(j, v2, op2) % 7] = true;
				}
			}
		}
		if (dp[n][0]) cout << "LUCKY\n";
		else cout << "UNLUCKY\n";
	}
}