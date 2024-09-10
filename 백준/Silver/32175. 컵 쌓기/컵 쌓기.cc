#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

int main(void)
{
    int n, h; cin >> n >> h;

    vector<int> arr(n);
    vector<int> dp(h + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= h; i++) {
        int sum = 0;

        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 0) {
                sum = (dp[i - arr[j]] + sum) % mod;
            }
        }

        dp[i] = sum;
    }

    cout << dp[h];
    return 0;
}