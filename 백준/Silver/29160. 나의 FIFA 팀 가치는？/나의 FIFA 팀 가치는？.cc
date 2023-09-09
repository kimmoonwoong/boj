#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    priority_queue<int>pq[12];

    for (int i = 0; i < n; i++) {
        int p, w; cin >> p >> w;
        pq[p].push(w);
    }
    
    while(k--){
        for(int i = 1;i<=11;i++){
            if(pq[i].empty()) continue;
            else{
                int k = pq[i].top();
                pq[i].pop();
                pq[i].push(k - 1);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=11;i++){
        if(pq[i].empty()) continue;
        else{
            ans += pq[i].top();
        }
    }
    cout << ans;


    return 0;
}