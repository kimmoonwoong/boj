#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int w[100][100][100];
bool visi[100][100][100];
int INF = 1e9;
int n;
int Find(int s, int k)
{
    int min_dist = INF;
    int min_idx = -1;
    
    for(int i = 0;i<n;i++){
        if(visi[k][s][i]) continue;
        
        if(w[k][s][i] < min_dist){
            min_dist = w[k][s][i];
            min_idx = i;
        }
    }
    
    return min_idx;
}
void Dekkers(int s, int k, vector<vector<pii>> list){
    w[k][s][s] = 0;
    visi[k][s][s] = true;
    
    for(pii next : list[s]){
        if(next.first == k) continue;
        
        w[k][s][next.first] = next.second;
    }
    
    for(int i = 0;i<n - 1;i++){
        int node = Find(s, k);
        
        if(node == -1) break;
        visi[k][s][node] = true;
        
        for(pii next : list[node]){
            if(visi[k][s][next.first]) continue;
            if(next.first == k) continue;
            
            if(w[k][s][next.first] > w[k][s][node] + next.second)
                w[k][s][next.first] = w[k][s][node] + next.second;
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int m, q; cin >> n >> m >> q;
    
    vector<vector<pii>> list(n + 1);
    
    for(int i = 0;i<m;i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        list[a].push_back({b, c});
    }
    fill_n(&w[0][0][0], 100*100*100, INF);
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i == j) continue;
            Dekkers(j, i, list);
        }
    }
    
    for(int i = 0;i<q;i++){
        int s, k, e; cin >> s >> k >> e;
        s--; k--; e--;
        if(w[k][s][e] == INF) cout << "No\n";
        else cout << w[k][s][e] << "\n";
    }
}