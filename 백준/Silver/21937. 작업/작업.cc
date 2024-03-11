#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> list(100001);
bool visi[100001];
int ans = 0;
void DFS(int node){
    visi[node] = true;
    if(list[node].size() == 0) return;
    
    for(int next: list[node]){
        if(visi[next]) continue;
        
        ans+= 1;
        DFS(next);
    }
    
    return ;
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0;i<m;i++)
    {
        int a, b; cin >> a >> b;
        list[b].push_back(a);
    }
    int s; cin >> s;
    DFS(s);
    
    cout << ans;
}