#include <stdio.h>
#include <cmath>
using namespace std;

int arr[1001];
int dp[1001][31][2];
int main(void){
    int t,w;
    scanf("%d %d", &t, &w);
    for (int i = 1; i <= t; ++i) scanf("%d", &arr[i]);
    for (int i = 0; i <= w; ++i) {
        for (int j = 1; j <= t; ++j) {
            if (i == 0){
                dp[j][i][0] = dp[j - 1][i][0] + (arr[j] == 1);
            }
            else{
                dp[j][i][0] = max(dp[j - 1][i - 1][1] + (arr[j] == 1), dp[j - 1][i][0] + (arr[j] == 1));
                dp[j][i][1] = max(dp[j - 1][i][1] + (arr[j] == 2), dp[j - 1][i - 1][0] + (arr[j] == 2));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; ++i) {
        ans = max(ans, max(dp[t][i][0], dp[t][i][1]));
    }
    printf("%d", ans);
    return 0;
}