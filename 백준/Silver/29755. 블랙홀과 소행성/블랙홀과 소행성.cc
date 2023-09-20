#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
long long arr[200001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        long long a, w; cin >> a >> w;
        int idx = lower_bound(arr, arr + n, a) - arr;
        long long k = 0;
        if (idx == n) k = abs(arr[idx - 1] - a) * w;
        else if (idx == 0) k = abs(arr[idx] - a) * w;
        else k = min({abs(arr[idx] - a), abs(arr[idx - 1] - a)}) * w;
        ans = max(ans, k);
    }
    cout << ans;

}