#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n, l; cin >> n >> l;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        arr[i] = { s, e  };
    }

    sort(arr.begin(), arr.end());

    int x = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x >= arr[i].second) continue;

        x = max(x, arr[i].first);

        int cnt = (arr[i].second - (x + 1)) / l + 1;
        ans += cnt;
        x += cnt * l;
    }
    cout << ans;
}