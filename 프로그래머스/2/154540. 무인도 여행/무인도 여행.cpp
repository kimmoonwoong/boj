#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int, int>
#include <iostream>
using namespace std;

int next_x[4] = {1, -1, 0, 0};
int next_y[4] = {0, 0, 1, -1};

int BFS(vector<string> map, vector<vector<bool>> &visi, pii s){
    queue<pii> q;
    q.push(s);
    int n = map.size(), m = map[0].length();
    visi[s.first][s.second] = true;
    int cnt = map[s.first][s.second] - '0';

    while(!q.empty()){
        pii now = q.front();
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nextx = next_x[i] + now.first;
            int nexty = next_y[i] + now.second;
            
            if(nextx < 0 || nexty < 0 || nextx >=n || nexty>=m) continue;
            if(map[nextx][nexty] == 'X') continue;
            if(visi[nextx][nexty]) continue;
            
            cnt+= map[nextx][nexty] - '0';
            visi[nextx][nexty] = true;
            q.push({nextx, nexty});
        }
    }
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visi(maps.size(), vector<bool>(maps[0].length()));
    
    for(int i = 0;i<maps.size();i++){
        for(int j = 0;j<maps[i].length();j++){
            if(maps[i][j] == 'X') continue;
            if(visi[i][j]) continue;
            
            int cnt = BFS(maps, visi, {i, j});
            answer.push_back(cnt);
        }
    }
    
    if(answer.size() == 0) return {-1};
    else{
        sort(answer.begin(), answer.end());
        return answer;
    }
}