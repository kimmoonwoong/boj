#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll x = 0, y = 1e9;
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            x += (arr[i] - arr[i - 1]);
            y = min(y, x) + arr[i + 1] - arr[i];
        }
    }
    cout << y;
    return 0;
}