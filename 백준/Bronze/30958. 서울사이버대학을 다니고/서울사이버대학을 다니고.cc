#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define pii pair<int, int>
#define ll long long
using namespace std;

    
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int cnt = 0;
    map<char, int> mp;
    
    while (true) {
        if (cnt >= n) break;
        string s; cin >> s;
        cnt += s.length() + 1;
        for (char c : s) {
            mp[c]++;
        }
    }
    int ans = 0;
    for (auto now : mp) {
        ans = max(now.second, ans);
    }
    cout << ans;
    return 0;
}