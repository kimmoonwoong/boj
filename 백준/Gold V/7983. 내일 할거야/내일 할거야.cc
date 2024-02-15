#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;


int main() {
    int n; cin >> n;
    vector<pll> arr(n);
    for (int i = 0; i < n; i++) {
        ll d, t; cin >> d >> t;
        arr[i] = { t, d };
    }

    sort(arr.begin(), arr.end(), greater<pll>());
    
    ll ans = arr[0].F - arr[0].S;
    for (int i = 1; i < n; i++) {
        if (ans >=arr[i].F ) ans = arr[i].F - arr[i].S;
        else ans -= arr[i].S;
    }
    cout << ans;
}