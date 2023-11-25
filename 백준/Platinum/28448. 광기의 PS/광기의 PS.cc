#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<long long, long long>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, l; cin >> n >> l;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        ll k, t; cin >> k >> t;
        arr[i] = { k, t };
    }
    sort(arr.begin(), arr.end());
    ll cur = 0;
    ll time = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (cur + (arr[i].first * arr[i].second) > l) {
            time += arr[i].second + ((cur +  arr[i].first * arr[i].second) - l);
            cur = l;
            cur -= min(arr[i].first * arr[i].second, arr[i].first * 5);
        }
        else {
            time += arr[i].second;
            cur += arr[i].second * arr[i].first;
            cur -= min(arr[i].first * arr[i].second, arr[i].first * 5); 
        }
    }
    cout << time;
}