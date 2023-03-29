#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

int arr[101];
int dp[10001];
int main(void){
    int n, k; cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] += dp[j - arr[i]];
        }
    }
    cout << dp[k];
    return 0;
}