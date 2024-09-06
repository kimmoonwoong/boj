#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, m; cin >> n >> m;
    
    ll t = 0;
    vector<ll> arr(m + 1);
    arr[0] = 0;
    for(int i = 1;i<=m;i++){
        ll k, p; cin >> k >> p;
        
        if(k == 1){
            t = (t + (p % n)) % n;
        }
        else if(k == 2){
            t = (t - (p % n) + n) % n;
        }
        else{
            t = arr[p];
        }
        
        arr[i] = t;
    }
    cout << t + 1;
    return 0;
}