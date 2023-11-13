#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    vector<ll> t(n);
    vector<ll> b(n);
    vector<ll> c(n);

    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    for (int i = 1; i < n; i++) {
        int idx = lower_bound(t.begin(), t.end(), t[i] - b[i]) - t.begin() - 1;

        if (idx == -1) {
            c[i] = max(c[i], c[i - 1]);
        }
        else {
            c[i] = max(c[i] + c[idx], c[i - 1]);
        }
    }
    cout << c[n - 1];
}