#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int next_x[8][3] = {{-1, -1, -1}, {-1, -1, -1}, {0, -1, -1}, {0, 1, 1}, {0, -1, -1}, {0, 1, 1}, {1, 1, 1,}, {1, 1, 1}};
int next_y[8][3] = {{0, -1, -1}, {0, 1, 1}, {1, 1, 1}, {1, 1, 1}, {-1, -1, -1}, {-1, -1, -1}, {0, -1, -1}, {0, 1, 1}};

bool visi[10][9];
struct Node{
    int x, y, cnt;
};

int main(){
    int sx, sy; cin >> sx >> sy;
    int ex, ey; cin >> ex >> ey;
    
    queue<Node> q;
    q.push({sx, sy, 0});
    visi[sx][sy] = true;
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        
        if(now.x == ex && now.y == ey){
            cout << now.cnt;
            exit(0);
        }
        
        for(int i = 0;i<8;i++){
            int nextx = now.x;
            int nexty = now.y;
            bool check = false;
            for(int j = 0;j<3;j++){
                nextx += next_x[i][j];
                nexty += next_y[i][j];
                
                if(nextx <0 || nexty < 0 || nextx >= 10 || nexty >= 9){
                    check = true;
                    break;   
                }
                if(j != 2 && (nextx == ex && nexty == ey)){
                    check = true;
                    break;   
                }
            }
            if(check) continue;
            if(visi[nextx][nexty]) continue;
            visi[nextx][nexty] = true;
            q.push({nextx, nexty, now.cnt + 1});
        }
    }
    cout << -1;
}