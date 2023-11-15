#include <string>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

struct XY{
    int x;
    int y;
    int l;
    int cnt;
};

int next_x[4] = {1, -1, 0, 0};
int next_y[4] = {0, 0, 1, -1};

int solution(vector<string> maps) {
    vector<vector<vector<bool>>> visi(maps.size(), vector<vector<bool>>(maps[0].length(), vector<bool>(2)));
    pii s;
    int n = maps.size();
    int m = maps[0].length();
    for(int i = 0;i<maps.size();i++){
        for(int j = 0;j<maps[i].length();j++){
            if(maps[i][j] == 'S') s = {i, j};
        }
    }
    queue<XY> q;
    q.push({s.first, s.second, 0, 0});
    visi[s.first][s.second][0] = true;
    
    while(!q.empty()){
        XY now = q.front();
        q.pop();
        
        if(maps[now.x][now.y] == 'E' && now.l == 1){
            return now.cnt;
        }
        
        for(int i = 0;i<4;i++){
            int nextx = now.x + next_x[i];
            int nexty = now.y + next_y[i];
            
            if(nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
            if(maps[nextx][nexty] == 'X') continue;
            if(visi[nextx][nexty][now.l]) continue;
            
            if(maps[nextx][nexty] == 'L'){
                visi[nextx][nexty][1] = true;
                q.push({nextx, nexty, 1, now.cnt + 1});
                continue;
            }
            
            visi[nextx][nexty][now.l] = true;
            q.push({nextx, nexty, now.l, now.cnt + 1});
        }
    }
    
    return -1;
}