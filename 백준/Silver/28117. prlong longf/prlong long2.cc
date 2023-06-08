#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int dp[81];
map<int, int> mp;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> vec;
    dp[0] = 1;
    dp[-1] = 1;
    for (int i = 0; i < n; i++) {
        int k = i - 1 < 0 ? 0 : i - 1;
        if (s.substr(i, 8) == "longlong") {
            if (vec.size() == 0) dp[i + 7] = dp[k] + 1;
            else dp[i + 7] += (dp[k] + dp[vec[vec.size() - 1]]);
            vec.push_back(i + 7);
            mp.insert({ i + 7, 1 });
        }
        auto it = mp.find(i);
        if (it != mp.end()) continue;
        else dp[i] = dp[k];
    }
    if (vec.empty()) cout << 1;
    else cout << dp[vec[vec.size() - 1]];
}
