#include <algorithm>
#include <iostream>
using namespace std;
int arr[6][2];
int dp[1000001];
int main() {
    int A,B,C,K; cin >> A >> B >> C >> K;
    arr[0][0] = A*4; arr[0][1] = 4;
    arr[1][0] = B*4; arr[1][1] = 4;
    arr[2][0] = A*2 + C; arr[2][1] = 3;
    arr[3][0] = B*2 + C; arr[3][1] = 3;
    arr[4][0] = C*2; arr[4][1] = 2;
    arr[5][0] = A+B; arr[5][1] = 2;
    dp[0] = 0;
    for(int i = 1;i<=K;i++){
        dp[i] = 1000001;
        for(int j = 0;j<6;j++){
            if(i - arr[j][0] >=0){
                dp[i] = min(dp[i - arr[j][0]] + arr[j][1], dp[i]);
            }
        }
    }
    if(dp[K] == 1000001) cout<<-1;
    else cout << dp[K];
    return 0;
}