#include <iostream>
#include <vector>
#include <algorithm>
#define pll pair<ll, ll>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pll> arr(n);
    for (int i = 0; i < n; i++) {
        int h, o; cin >> h >> o;
        if (h > o) arr[i] = { o, h };
        else arr[i] = { h, o };
    }
    int d; cin >> d;
    vector<pll> check;
    for (int i = 0; i < n; i++) {
        if (arr[i].first + d < arr[i].second) continue;
        check.push_back({ arr[i].first, 1 });
        check.push_back({ arr[i].second - d, -1 });
    }
    sort(check.begin(), check.end());

    int cnt = 0, ans = 0;
    for (int i = 0; i < check.size(); i++) {
        cnt -= check[i].second;
        if (cnt > ans) ans = cnt;
    }
    cout << ans;
}