#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long INF = 2e9;
int main(){
    int n; long long d; cin >> n >> d;
    vector<long long> mons;
    vector<long long> arm;
    
    for(int i = 0;i<n;i++){
        int a; long long x; cin >> a >> x;
        if(a == 1) mons.push_back(x);
        else arm.push_back(x);
    }
    sort(mons.begin(), mons.end());
    sort(arm.begin(), arm.end());
    int ans = 0;
    int acnt = 0;
    int bcnt = 0;
    while(1){
        if(bcnt >= mons.size()) break;
        if(mons[bcnt] < d){
            d += mons[bcnt];
            ans++;
            bcnt++;
        }
        else{
            if(acnt >= arm.size()) break;
            d *= arm[acnt];
            ans++;
            acnt++;
        }
        if(d > INF) d = INF;
    }
    ans += arm.size() - acnt;
    cout << ans;
    
}