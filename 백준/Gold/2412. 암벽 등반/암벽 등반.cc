#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define pii pair<int, int>

using namespace std;

struct XY{
  int x;
  int y;
  int cnt;
};

bool cmp(pii o1, pii o2){
    return o1.second < o2.second;
}
int main(){
    int n, t; cin >> n >> t;
    vector<pii> arr(n);
    map<pii, bool> visi;
    for(int i = 0;i<n;i++){
        int x, y; cin >> x >> y;
        arr[i] = {x, y};
        visi[{x, y}] = false;
    }
    sort(arr.begin(), arr.end(), cmp);
    queue<XY> q;
    q.push({0,0,0});
    
    while(!q.empty()){
        XY now = q.front();
        q.pop();
        
        if(now.y == t){
            cout << now.cnt;
            return 0;
        }
        int idx = lower_bound(arr.begin(), arr.end(), make_pair(0, now.y - 2), cmp) - arr.begin();
        for(int i = idx; i<n;i++){
            if(abs(arr[i].second - now.y) > 2) break;
            if(visi[arr[i]]) continue;
            if(abs(arr[i].first - now.x) > 2) continue;
            visi[arr[i]]= true;
            q.push({arr[i].first, arr[i].second, now.cnt + 1});
        } 
    }
    cout << -1;
}