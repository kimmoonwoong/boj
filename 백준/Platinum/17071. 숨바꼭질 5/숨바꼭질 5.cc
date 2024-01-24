#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;

bool visi[500001][2];
int nexts[3] = {1, -1, 2};

struct Node
{
    int now, cnt, before;
};
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    
    queue<Node> q;
    q.push({n, 0, k});
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        int ks = now.before + now.cnt;
        if(ks > 500000){
            cout << -1;
            break;
        }
        if(ks == now.now || visi[ks][now.cnt % 2]){
            cout << now.cnt;
            break;
        }
        
        for(int i =0; i<3;i++){
            int nextx = now.now;
            if(nexts[i] > 1) nextx *= nexts[i];
            else nextx += nexts[i];
            
            if(nextx < 0 || nextx > 500000) continue;
            if(visi[nextx][(now.cnt + 1) % 2]) continue;
            visi[nextx][(now.cnt + 1) % 2] = true;
            q.push({nextx, now.cnt + 1, ks});
        }
    }
}