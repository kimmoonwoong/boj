#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;
        vector<ll> arr(n);
        
        for(int i = 0;i<n;i++) cin >> arr[i];
        ll ans = 0;
        ll val = 0;
        for(int i = n -1;i>=0;i--){
            val = max(val, arr[i]);
            ans += val - arr[i];
        }
        cout << ans << "\n";
    } 
}