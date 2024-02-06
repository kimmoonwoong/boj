#include <iostream>
#include <vector>
#include <string>
using namespace std;
int INF = 1e9;

int main() {
    int n; cin >> n;
    vector<vector<int>> dist(n, vector<int>(n, INF));    
    for(int i = 0;i<n;i++){
        string s; cin >> s;
        
        for(int j = 0;j<n;j++){
            if(s[j] == 'Y') dist[i][j] = 1;
        }
    }
    
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(i == j) continue;
            if(dist[i][j] <= 2) cnt++;
        }
        ans = max(cnt, ans);
    }
    cout << ans;
    
    return 0;
}