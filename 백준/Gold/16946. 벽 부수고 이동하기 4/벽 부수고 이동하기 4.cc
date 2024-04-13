#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#define pii pair<int, int>
using namespace std;

struct XY{
    int x, y;
};

int next_x[4] = {1, -1, 0, 0};
int next_y[4] = {0, 0, 1, -1};

int n, m;
int ans[1001][1001];
int arr[1001][1001];
bool visi[1001][1001];

void BFS(XY s){
    queue<XY> q;
    q.push(s);
    visi[s.x][s.y] = true;
    int cnts = 0;
    set<pii> check;
    while(!q.empty()){
        XY now = q.front();
        q.pop();
        
        cnts++;
        for(int i = 0;i<4;i++){
            int nextx = now.x + next_x[i];
            int nexty = now.y + next_y[i];
            
            if(nextx < 0 || nexty < 0 || nextx >= n || nexty >=m) continue;
            if(visi[nextx][nexty]) continue;
            
            if(arr[nextx][nexty]) {
                check.insert({nextx, nexty});
                continue;
            }
            
            visi[nextx][nexty] = true;
            q.push({nextx,nexty});
        }
    }
    for(auto now : check){
        ans[now.first][now.second] += cnts;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for(int i = 0;i<n;i++){
        string s; cin >> s;
        for(int j = 0;j<m;j++){
            arr[i][j] = stoi(s.substr(j, 1));
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]) continue;
            if(visi[i][j]) continue;
            
            BFS({i, j});
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j] == 1) cout << (ans[i][j] + 1) % 10;
            else cout << 0;
        }
        cout << "\n";
    }
    return 0;
}