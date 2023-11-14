#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100001];
int dp[100001][2];
int main(){
    int n; cin >> n;
    for(int i = 1;i<=n;i++) cin >> arr[i];
    int ans = arr[1];
    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    for(int i = 2;i<=n;i++){
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
}