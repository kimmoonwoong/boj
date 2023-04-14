#include <iostream>
using namespace std;


int V[51];
int dp[51][1002];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,s,m; cin >> n >> s >> m;
    for (int i = 1; i <= n; ++i) cin >> V[i];
    dp[0][s] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dp[i - 1][j] == 1){
                if (j + V[i] <= m) {
                    dp[i][j + V[i]] = 1;
                }
                if (j - V[i] >= 0) dp[i][j - V[i]] = 1;
            }
        }
    }
    for (int i = m; i >=0 ; --i) {
        if (dp[n][i] == 1){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}   