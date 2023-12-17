#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int j, n; cin >> j >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            int r, c; cin >> r >> c;
            arr[i] = r * c;
        }

        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (j <= 0) break;
            j -= arr[i];
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}