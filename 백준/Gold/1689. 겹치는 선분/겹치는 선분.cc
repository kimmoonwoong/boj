#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int>> arr;
    for(int i = 0;i<n;i++){
        int s, e; cin >> s >> e;
        arr.push_back({s, 1});
        arr.push_back({e, -1});
    }   
    
    sort(arr.begin(), arr.end());
    int cnt = 0, ans = 0;
    for(pair<int, int> now : arr){
        cnt += now.second;
        ans = max(cnt, ans);
    }   
    cout << ans;
}