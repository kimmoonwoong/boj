#include <iostream>

using namespace std;
int dp[1001][1001];
pair<int, int> arr[1001];
int main(){
    int n, t; cin >> n >> t;
    int sum = 0;
    for(int i = 1;i<=n;i++){
        int d, m; cin >> d >> m;
        sum += m;
        arr[i] = {d, m};
    }
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=t;j++){
            dp[i][j] = dp[i - 1][j];
            if(arr[i].first <= j){
                int k = max(dp[i][j], dp[i - 1][j - arr[i].first] + arr[i].second);
                dp[i][j] = max(dp[i][j], k);
            }
        }
    }
    cout << sum - dp[n][t];
}