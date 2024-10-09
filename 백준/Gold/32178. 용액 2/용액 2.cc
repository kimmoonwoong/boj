#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<ll, ll>
#define ll long long
using namespace std;



int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<ll> arr(n);
    vector<pii> nodearr;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll sum = arr[0];
    nodearr.push_back({ 0, 0 });
    for (int i = 1; i < n + 1; i++) {
        nodearr.push_back({ sum, i });
        if (i < n)
            sum += arr[i];
    }

    sort(nodearr.begin(), nodearr.end());

    ll l = 0, r = 0;
    ll ans = 1e9 + 7;

    for (int i = 1; i < nodearr.size(); i++) {

        if (abs(nodearr[i].first - nodearr[i - 1].first) < abs(ans)) {
            l = nodearr[i - 1].second;
            r = nodearr[i].second;
            ans = nodearr[i].first - nodearr[i - 1].first;

            if (l > r) {
                swap(l, r);
                ans *= -1;
            }
        }
    }
    cout << ans << "\n" << l + 1 << " " << r;
    return 0;
}