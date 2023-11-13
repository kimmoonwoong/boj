#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        arr[i] = { l, r };
    }
    int ans = 0;
    int curl = arr[0].first, curr = arr[0].second;
    if (curl != 0 && curr != 0 && curl == curr) ans++;
    
    for (int i = 1; i < n; i++) {
        if (arr[i].first != 0 && curl == arr[i].first) ans++;
        if (arr[i].second != 0 && curr == arr[i].second) ans++;
        if (arr[i].first!= 0 && arr[i].second!= 0 && arr[i].first == arr[i].second) ans++;
        curl = arr[i].first, curr = arr[i].second;
    }
    cout << ans;
}