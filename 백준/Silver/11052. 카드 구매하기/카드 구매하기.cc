#include <cstdio>
#include <iostream>

using namespace std;
int arr[1000];
int dp[1000];
int main(void){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for (int i = 2; i <= n; ++i) {
        int dpmax = 0;
        int index = 1;
        for (int j = i - 1; j >= 1; --j) {
            dpmax = max((dp[j] + arr[index]), dpmax);
            if (i % j == 0) dpmax = max(arr[j] * (i / j), dpmax);
            index++;
        }
        dp[i] = max(dpmax, arr[i]);
    }
    cout << dp[n];
    return 0;
}