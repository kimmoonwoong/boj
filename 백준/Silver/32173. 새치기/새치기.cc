#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    
    ll p = 0;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ll s; cin >> s;
        ans = max(ans, s - p);
        p += s;
    }
    cout << ans;
    return 0;
}