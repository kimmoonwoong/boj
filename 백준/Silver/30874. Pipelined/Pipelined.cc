#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define pii pair<int, int>
#define ll long long
using namespace std;




int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int maxs = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        maxs = max(maxs, k);
    }
    cout << maxs + (n - 1);
}