#include <iostream>
using namespace std;

int dp[101][10001];
int times[1001];
int score[1001];
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,T; cin >> n >> T;
    for(int i = 1;i<=n;i++){
        cin >> times[i] >> score[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=T;j++){
            if(j - times[i] >=0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - times[i]] + score[i]);
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][T];
	return 0;
}