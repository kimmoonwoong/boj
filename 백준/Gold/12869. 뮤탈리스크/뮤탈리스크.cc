#include <iostream>
#include<cstring>
using namespace std;
int arr[3];
int dp[61][61][61];
int dfs(int h1, int h2, int h3) {
    if (h1 < 0) return dfs(0, h2, h3);
    if (h2 < 0) return dfs(h1, 0, h3);
    if (h3 < 0) return dfs(h1, h2, 0);


    if (h1 == 0 && h2 == 0 && h3 == 0) {
        return 0;
    }
    if (dp[h1][h2][h3] != -1) return dp[h1][h2][h3];

    dp[h1][h2][h3] = 1e9;

    dp[h1][h2][h3] = min(dp[h1][h2][h3], dfs(h1 - 9, h2 - 3, h3 - 1) + 1);
    dp[h1][h2][h3] = min(dp[h1][h2][h3], dfs(h1 - 9, h2 - 1, h3 - 3) + 1);
    dp[h1][h2][h3] = min(dp[h1][h2][h3], dfs(h1 - 3, h2 - 9, h3 - 1) + 1);
    dp[h1][h2][h3] = min(dp[h1][h2][h3], dfs(h1 - 1, h2 - 9, h3 - 3) + 1);
    dp[h1][h2][h3] = min(dp[h1][h2][h3], dfs(h1 - 3, h2 - 1, h3 - 9) + 1);
    dp[h1][h2][h3] = min(dp[h1][h2][h3], dfs(h1 - 1, h2 - 3, h3 - 9) + 1);

    return dp[h1][h2][h3];
}
int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(arr[0], arr[1], arr[2]);
}