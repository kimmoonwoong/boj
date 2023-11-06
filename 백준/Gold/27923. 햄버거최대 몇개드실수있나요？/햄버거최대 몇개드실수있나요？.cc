#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(){
    int n, k, l; cin >> n >> k >> l;
    vector<int> ham(n + 1);
    vector<int> col(n + 1);
    
    for(int i = 1;i<=n;i++) cin >> ham[i];
    
    for(int i = 0;i<k;i++){
        int x; cin >> x;
        col[x]++;
        if(x + l < n) col[x + l]--;
    }
    partial_sum(col.begin(), col.end(), col.begin());
    sort(ham.begin() + 1, ham.end(), greater<int>());
    sort(col.begin() + 1, col.end(), greater<int>());
    long long ans = 0;
    for(int i = 1;i<=n; i++){
        ans += ham[i] >> min(col[i], 30);
    }
    cout << ans;
}