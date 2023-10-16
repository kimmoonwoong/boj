#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    set<pair<int, int>> nset, mset;
    map<int, int> nmp, mmp;

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        nmp[i] = k;
        nset.insert({ k, i });
    }
    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        mmp[i + n] = k;
        mset.insert({ k, i + n });
    }

    int k; cin >> k;
    vector<pair<int, int>> removes;
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        if (c == 'U') {
            int x, y; cin >> x >> y;
            if (x > n) {
                mmp[x] = y;
                mset.insert({ y, x });
            }
            else {
                nmp[x] = y;
                nset.insert({ y, x });
            }
        }
        else {
            for (auto n : nset) {
                if (nmp[n.second] != n.first) {
                    removes.push_back(n);
                }
                else {
                    cout << n.second << " ";
                    break;
                }
            }
            for (pair<int, int> p : removes) nset.erase(p);
            removes.clear();
            for (auto n : mset) {
                if (mmp[n.second] != n.first) {
                    removes.push_back(n);
                }
                else {
                    cout << n.second << "\n";
                    break;
                }
            }
            for (pair<int, int> p : removes) mset.erase(p);
        }
    }
}