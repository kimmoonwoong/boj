#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> list(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    vector<bool> visi(n + 1);
    int k; cin >> k;
    vector<int> arr(k);
    set<int> setk;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        setk.insert(arr[i]);
    }
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        bool isCheck = false;
        set<int> check;
        for (int next : list[arr[i]]) {
            if (setk.find(next) == setk.end()) {
                isCheck = true;
                break;
            }
        }
        if (!isCheck) ans.push_back(arr[i]);
    }
    for (int now: ans) {
        visi[now] = true;
        for (int next : list[now]) visi[next] = true;
    }
    bool isCheck = false;

    for (int i = 0; i < k; i++) {
        if (!visi[arr[i]]) isCheck = true;
    }

    if (isCheck) cout << -1;
    else {
        cout << ans.size() << "\n";
        for (int cur : ans) cout << cur << " ";
    }
}