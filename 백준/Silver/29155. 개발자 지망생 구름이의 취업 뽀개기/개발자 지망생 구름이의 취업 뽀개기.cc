#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[6];
int main(){
    int n; cin >> n;
    vector<vector<int>> arr(6);
    
    
    for(int i = 1;i<=5;i++) cin >> p[i];
    
    for(int i = 0;i<n;i++){
        int k, t; cin >> k >> t;
        arr[k].push_back(t);
    }
    for(int i = 1;i<=5;i++){
        sort(arr[i].begin(), arr[i].end());
    }
    int ans = 0;
    for(int i = 1;i<=5;i++){
        ans += arr[i][0];
        for(int j = 1;j<p[i];j++){
            ans += arr[i][j];
            ans += (arr[i][j] - arr[i][j - 1]);
        }

    }
    ans += 240;
    cout << ans;
    
    
}