#include <iostream>
#include <map>

using namespace std;

map<long long, long long> mp;
int main() {
    int n, k; cin >> n >> k;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long x, y; cin >> x >> y;

        long long l = -(k * x) + y;
        mp[l] += 1;
    }
    for (auto iter : mp) {
        ans += iter.second * (iter.second - 1) / 2;
    }
    cout << ans * 2;
}