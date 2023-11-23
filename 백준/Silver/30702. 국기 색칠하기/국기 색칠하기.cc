#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define pii pair<int, int>

using namespace std;

int next_x[4] = {1, -1, 0, 0};
int next_y[4] = {0, 0, 1, -1};
int n, m;

void BFS(pii start, vector<string> & mapA, vector<string> mapB, vector<vector<bool>> & visi){
    queue<pii> q;
    q.push(start);
    visi[start.first][start.second] = true;
    while(!q.empty()){
        pii now = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int nextx = now.first + next_x[i];
            int nexty = now.second + next_y[i];
            
            if(nextx < 0 || nexty < 0 || nextx >= n || nexty >=m) continue;
            if(visi[nextx][nexty]) continue;
            if(mapA[nextx][nexty] != mapA[start.first][start.second]) continue;
            mapA[nextx][nexty] = mapB[start.first][start.second];
            visi[nextx][nexty] = true;
            q.push({nextx, nexty});
        }
    }
    mapA[start.first][start.second] = mapB[start.first][start.second];
}

int main(){
    cin >> n >> m;
    
    vector<string> mapA(n);
    vector<string> mapB(n);
    vector<vector<bool>> visi(n, vector<bool>(m));
    for(int i = 0;i<n;i++) cin >> mapA[i];
    for(int i = 0;i<n;i++) cin >> mapB[i];
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visi[i][j]) continue;
            BFS({i, j}, mapA, mapB, visi);
        }
    }
    for(int i = 0;i<n;i++){
        if(mapA[i] != mapB[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}