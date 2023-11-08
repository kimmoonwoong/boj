#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, r; cin >> n >> m >> r;
    
    vector<int> arr(n);
    vector<int> dist;
    
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    for(int i = 0;i<n;i++){
        for(int j = i + 1;j<n;j++){
            dist.push_back(abs(arr[i] - arr[j]));
        }
    }
    
    vector<int> h(m);
    
    for(int i = 0;i<m;i++) cin >> h[i];
    
    sort(h.begin(), h.end());
    double ans = 0.0;
    bool check = false;
    for(int i = 0;i<dist.size();i++){
        int k = (int)r * 2 / dist[i];
        int idx = upper_bound(h.begin(), h.end(), k) - h.begin() - 1;
        if(k < h[0]) continue;
        
        ans = max(ans, (double)h[idx] * dist[i] / 2);
        check = true;
    }
    
    if(!check) cout << -1;
    else{
        cout.precision(1);
        cout << fixed;
        cout << ans;
    }
}