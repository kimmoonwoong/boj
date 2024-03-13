#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    
    vector<ll> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    for(int i = 1;i<arr.size();i++) arr[i] += arr[i - 1];
    
    int p = 0;
    for(int i = 0;i<m;i++){
        int q; cin >> q;
        
        if(q == 1){
            int k; cin >> k;
            p -= k;
            p = (p + n) % n;
        }
        else if(q == 2){
            int k; cin >> k;
            p += k;
            p = (p + n) % n;
        }
        else{
            int a, b; cin >> a >> b;
            a--;b--;
            a = (a + p) % n;
            b = (b + p) % n;

            if(a - 1 < 0){
                if(a > b) cout << arr[n - 1] + arr[b] << "\n"; 
                else cout << arr[b] << "\n";    
            }
            else{
                if(a > b) cout << (arr[n - 1] - arr[a - 1]) + arr[b] << "\n"; 
                else cout << arr[b] - arr[a - 1] << "\n";
            }
                
        }
    }
    return 0;
}