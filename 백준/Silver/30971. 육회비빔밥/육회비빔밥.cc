#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> arrA(n + 1);
    vector<int> arrB(n + 1);
    vector<int> arrC(n + 1);
    vector<int> arrIdx;
    for (int i = 1; i <= n; i++) arrIdx.push_back(i);
    for (int i = 1; i <= n; i++) cin >> arrA[i];
    for (int i = 1; i <= n; i++) cin >> arrB[i];
    for (int i = 1; i <= n; i++) cin >> arrC[i];

    int ans = 0;
    do {
        int cur = 0;
        int curc = 0;
        for (int i = 1; i < n; i++) {
            cur += arrA[arrIdx[i - 1]] * arrB[arrIdx[i]];
            curc = arrC[arrIdx[i - 1]] * arrC[arrIdx[i]];
            if (curc > k) break;
        }
        if (curc <= k) ans = max(cur, ans);
    } while (next_permutation(arrIdx.begin(), arrIdx.end()));
    if (ans == 0) cout << -1;
    else cout << ans;
}