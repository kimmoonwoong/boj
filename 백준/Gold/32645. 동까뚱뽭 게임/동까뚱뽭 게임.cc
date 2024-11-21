#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

bool typed[100001];
int INF = 1e9;
bool visi[100001];
vector<vector<int>> edge(100001);
bool DFS(int n){
    visi[n] = true;
    bool check = false;
    for(int k : edge[n]){
        if(visi[k])
            continue;
            
        if(!DFS(k)){
            check = true;
        }
    }
    typed[n] = check;
    return check;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i = 0;i<n - 1;i++){
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    DFS(1);
    
    for(int i = 1;i<=n;i++){
        if(!typed[i])
            cout << "uppercut\n";
        else
            cout << "donggggas\n";
    }
    return 0;
}
