#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<ll, ll>
#define ll long long
using namespace std;

int main() {
    ll n, m, k; cin >> n >> m >> k;
    vector<pii> arr(k);
    for(int i = 0;i<k;i++){
        ll v, c; cin >> v >> c;
        arr[i] = {c, v};
    }
    
    sort(arr.begin(), arr.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    for(int i = 0;i<k;i++){
        sum += arr[i].second;
        pq.push(arr[i].second);
        
        if(pq.size() > n){
            sum -= pq.top();
            pq.pop();
        }
        
        if(pq.size() == n && sum >= m){
            cout << arr[i].first;
            return 0;
        }
    }
    cout << -1;
    return 0;
}