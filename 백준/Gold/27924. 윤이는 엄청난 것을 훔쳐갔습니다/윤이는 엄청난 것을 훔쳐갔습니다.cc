#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
void BFS(int start, vector<vector<int>> list, vector<vector<int>>& riff
    ){
    queue<pair<int, int>> q;
    vector<bool> visi(n + 1);
    q.push({start, 0 });
    visi[start] = true;
    if(list[start].size() == 1) riff[start].push_back(0);
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        
        for(int next: list[now.first]){
            if(visi[next]) continue;
            
            if(list[next].size() == 1){
                riff[next].push_back(now.second + 1);
            }
            
            visi[next] = true;
            q.push({next, now.second + 1});
        }
    }
}

int main(){
    cin >> n;
    vector<vector<int>> list(n + 1);
    vector<bool> visi(n + 1);
    vector<vector<int>> riff(n + 1);
    for(int i = 0;i<n -1;i++){
        int a, b; cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    
    int a, b, c; cin >> a >> b >> c;
    
    BFS(b, list, riff);
    BFS(c, list, riff);
    BFS(a, list, riff);
    for(int i = 1;i<=n;i++){
        if(riff[i].size() != 0){
            if(riff[i][2] < riff[i][1] && riff[i][2] < riff[i][0]){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}