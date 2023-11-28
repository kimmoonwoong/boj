#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int next_x[4] = {1,-1,0,0};
int next_y[4] = {0,0,1,-1};

int main(){
    int n, m; cin >> n >> m;
    
    vector<string> map(n);
    pii s;
    for(int i = 0;i<n;i++){
        cin >> map[i];
        for(int j = 0;j<m;j++){
            if(map[i][j] == 'I'){
                s = {i, j};  
            }
        }
    }
    
    vector<vector<bool>> visi(n, vector<bool>(m));
    queue<pii> q;
    q.push(s);
    visi[s.first][s.second] = true;
    int ans = 0;
    while(!q.empty()){
        pii now = q.front();
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nextx = now.first + next_x[i];
            int nexty = now.second + next_y[i];
            
            if(nextx < 0 | nexty<0 || nextx>=n || nexty >=m) continue;
            if(visi[nextx][nexty]) continue;
            if(map[nextx][nexty] == 'X') continue;
            if(map[nextx][nexty] == 'P') ans++;
            visi[nextx][nexty] = true;
            q.push({nextx, nexty});
        }
    }
    if(ans == 0) cout << "TT";
    else cout << ans;
}