#include <iostream>
#include <cmath>
using namespace std;

int ccw(int x1, int y1, int x2, int y2){
    int k = x1 * y2 - y1 * x2;
    
    if(k < 0) return -1;
    else if(k > 0) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q; cin >> q;
    
    while(q--){
        int x1,y1,x2,y2,w; cin >> x1 >> y1 >> x2 >> y2 >> w;
        
        int dist = (int)sqrt(w);
        int cnt = 0;
        for(int x = 1;x<=dist;x++){
            int y = sqrt(w - x * x);
            if(w == x * x + y * y){
                if(ccw(x1, y1, x, y) * ccw(x2, y2, x, y) <= 0) cnt++;
            }
        }
        cout << cnt << "\n";
    }
}