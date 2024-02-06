#include <iostream>
#include <vector>
using namespace std;

int color[200001];
vector<int> list[200001];
int ans = 0;
void DFS(int cur, int parent){
    if(!list[cur].size()) return;
    
    if(color[cur] != color[parent]) ans++;
    
    for(int next: list[cur]){
        if(next == parent) continue;
        
        DFS(next, cur);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i = 1;i<=n;i++) cin >> color[i];
    
    for(int i = 0;i<n - 1;i++){
        int a, b; cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    if(color[1] != 0) ans++;
    DFS(1, 1);
    cout << ans;
    return 0;
}