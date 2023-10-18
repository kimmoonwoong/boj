#include <iostream>
#include <map>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    map<int, pair<int, int>> mp;
    for (int i = 0; i < m; i++) {
        int k, s, e; cin >> k >> s >> e;
        if (mp.count(k) == 0) {
            mp[k] = { s, e };
            cout << "YES\n";
        }
        else {
            if (mp[k].second <= s) {
                mp[k] = { s, e };
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
}