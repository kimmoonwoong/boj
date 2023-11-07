#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    
    map<int, int> mp;
    for(int i = 0;i<n;i++){
        int k; cin >> k;
        mp[k]++;
    }
    int ans = 0;
    for(auto nw : mp){
        ans++;
        mp[nw.first]--;
    }
    
    for(auto nw: mp){
        if(nw.second == 0) continue;
        ans++;
    }
    cout << ans;
}