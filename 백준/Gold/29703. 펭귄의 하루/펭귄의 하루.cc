#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int next_x[4] = {1, -1, 0, 0};
int next_y[4] = {0, 0, 1, -1};
struct XY{
    int x;
    int y;
    int cnt;
};
string map[1001];
int n = 0, m = 0;
void BFS(XY start, vector<vector<int>> &mp){
    queue<XY> q;
    q.push(start);
    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[start.x][start.y] = true;
    
    while(!q.empty()){
        XY now = q.front();
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nextx = now.x + next_x[i];
            int nexty = now.y + next_y[i];
            
            if(nextx < 0 || nexty<0|| nextx>=n || nexty >=m) continue;
            if(visited[nextx][nexty]) continue;
            if(map[nextx][nexty] == 'D') continue;
            
            mp[nextx][nexty] = now.cnt + 1;
            XY next = {nextx, nexty, now.cnt + 1};
            visited[next.x][next.y] = true;
            q.push(next);
        } 
    }
}

int main(){
    cin >> n >> m;
    XY s;
    XY e;
    vector<pair<int, int>> target;
    for(int i = 0;i<n;i++){
        cin >> map[i];
        for(int j = 0;j<m;j++){
            if(map[i][j] == 'S'){
                s = {i, j, 0};         
            }
            else if(map[i][j] == 'H'){
                e = {i, j, 0};
            }
            else if(map[i][j] == 'F'){
                target.push_back({i, j});
            }
        }
    }
    vector<vector<int>> smap(n, vector<int>(m));
    vector<vector<int>> emap(n, vector<int>(m));
    BFS(s, smap);
    BFS(e, emap);
    
    int ans = 1e9;
    for(auto k : target){
        if(smap[k.first][k.second] == 0 || emap[k.first][k.second] == 0) continue;
        else{
            int sum = smap[k.first][k.second] + emap[k.first][k.second];
            ans = min(sum, ans);
        }
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
}