#include <cstdio>
#include <iostream>

using namespace std;
int arr[33][33];
long long dp[33][33][3];
int main(void){
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }

    dp[1][2][1] = 1;

    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=n; ++j) {
            if (arr[i][j] == 1) continue;

            dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j][2];
            dp[i][j][1] += dp[i][j - 1][1] + dp[i][j - 1][2];
            if(arr[i - 1][j] != 1 && arr[i][j - 1] != 1){
                dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }

        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    return 0;
}