#include <iostream>

using namespace std;
int aarr[101];
int barr[101];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> aarr[i];
    for (int i = 0; i < n; i++) cin >> barr[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (aarr[i] > barr[i]) ans += (aarr[i] - barr[i]);
    }
    cout << ans;
    
}