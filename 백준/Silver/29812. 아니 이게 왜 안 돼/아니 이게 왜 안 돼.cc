#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    int d, m; cin >> d >> m;
    map<char, int> mp;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H' || s[i] == 'Y' || s[i] == 'U') {
            if(cnt > 0) ans += min(m + d, d * cnt);
            cnt = 0;
            mp[s[i]]++;
        }
        else {
            cnt++;
        }
    }
    if(cnt > 0) ans += min(m + d, d * cnt);
    if (ans == 0)cout << "Nalmeok\n";
    else cout << ans << "\n";

    int mi = min({ mp['H'], mp['Y'], mp['U'] });

    if (mi == 0) cout << "I love HanYang University";
    else cout << mi;
}