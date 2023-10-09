#include <iostream>
#include <map>
#include <vector>
using namespace std;

int dp[2000001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        mp[a] = { b, c };
    }

    for (int i = 0; i <= 2000001; i++) {
        dp[i] = max(dp[i - 1], dp[i]);
        if (mp.count(i) != 0) {
            dp[i + mp[i].second] = max(dp[i + mp[i].second], dp[i] + mp[i].first);
        }
    }
    cout << dp[2000001];

}