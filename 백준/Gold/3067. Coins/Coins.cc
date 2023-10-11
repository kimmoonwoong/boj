#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)cin >> arr[i];
        int k; cin >> k;
        vector<int> dp(k + 1);

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i]; j <= k; j++) {
                dp[j] += dp[j - arr[i]];
            }
        }
        cout << dp[k] << "\n";
    }
  
}