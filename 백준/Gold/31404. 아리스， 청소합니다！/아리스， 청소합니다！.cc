#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

struct XY{
    int x, y, r;
};

int next_x[4] = {-1, 0, 1, 0};
int next_y[4] = {0, 1, 0, -1};
bool visi[64][64][4];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> ruleA(n, vector<int>(m));
    vector<vector<int>> ruleB(n, vector<int>(m));
    vector<vector<bool>> dust(n, vector<bool>(m));
    int sn, sm, sr; cin >> sn >> sm >> sr;
    for(int i = 0;i<n;i++) {
        string s; cin >> s;
        for(int j = 0;j<m;j++){
            ruleA[i][j] = stoi(s.substr(j, 1));
        }
    }
    for(int i = 0;i<n;i++){
        string s; cin >> s;
        for(int j = 0;j<m;j++) {
            ruleB[i][j] = stoi(s.substr(j, 1));
        }
    }
    
    XY s = {sn, sm, sr};  
    int cnt = 1;
    int ans = 0;
    XY last;
    while(true){
        bool check = false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!dust[i][j]){
                    check = true;
                    break;
                }
            }
            if(check) break;
        }
        if(!check) break;
        
        if(!dust[s.x][s.y]){
            int rotate = (s.r + ruleA[s.x][s.y]) % 4;
            int nextx = s.x + next_x[rotate];
            int nexty = s.y + next_y[rotate];
            dust[s.x][s.y] = true;
            ans += cnt;
            cnt = 1;
            s = {nextx, nexty, rotate};
            if(nextx < 0 || nexty < 0 || nextx >=n || nexty >=m) break;
            if(dust[nextx][nexty]) last = {nextx, nexty, rotate};
        }
        else{
            int rotate = (s.r + ruleB[s.x][s.y]) % 4;
            int nextx = s.x + next_x[rotate];
            int nexty = s.y + next_y[rotate];
            if(nextx < 0 || nexty < 0 || nextx >=n || nexty >=m) break;
            if(nextx == last.x && nexty == last.y && rotate == last.r) break;
            cnt++;
            s = {nextx, nexty, rotate};
        }
    }
    cout << ans;
    return 0;
}