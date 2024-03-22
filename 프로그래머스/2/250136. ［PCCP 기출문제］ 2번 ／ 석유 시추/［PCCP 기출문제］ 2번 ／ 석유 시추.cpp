#include <string>
#include <vector>
#include <map>
#include <queue>
#define pii pair<int, int>
using namespace std;

int next_x[4] = {1, -1, 0, 0};
int next_y[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    vector<vector<bool>> visi(n, vector<bool>(m));
    vector<int> arr(m);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(land[i][j] == 0) continue;
            if(visi[i][j]) continue;
            
            queue<pii> q;
            map<int, int> mp;
            int cnt = 0;
            visi[i][j] = true;
            q.push({i, j});
            while(!q.empty()){
                pii now = q.front();
                mp[now.second]++;
                cnt++;
                q.pop();
                
                for(int k = 0;k<4;k++){
                    int nextx = now.first + next_x[k];
                    int nexty = now.second + next_y[k];
                    
                    if(nextx < 0 || nexty < 0 || nextx >=n || nexty >=m) continue;
                    if(visi[nextx][nexty]) continue;
                    if(!land[nextx][nexty]) continue;
                    
                    visi[nextx][nexty] = true;
                    q.push({nextx, nexty});
                }
            }
            for(auto now : mp)
                arr[now.first] += cnt;
        }
    }
    
    for(int i = 0;i<m;i++){
        answer = max(answer, arr[i]);
    }
    return answer;
}