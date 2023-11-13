#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        vector<int> idx;
        vector<int> check(n, -1);
        for (int i = l; i <= r; i++) {
            idx.push_back(mp[i]);
        }
        sort(idx.begin(), idx.end());
        int cnt = l;
        for (int i = 0; i < idx.size(); i++) {
            check[idx[i]] = cnt;
            cnt++;
        }

        for (int i = 0; i < n; i++) {
            if (check[i] != -1) cout << check[i] << " ";
            else cout << arr[i] << " ";
        }
        cout << "\n";
    }

}