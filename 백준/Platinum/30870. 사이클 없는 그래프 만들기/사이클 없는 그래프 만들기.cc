#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

struct Info{
    int x;
    int y;
    int t;
    
    bool operator<(const Info &d) const{
        return t > d.t;
    }
};

queue<pii> q;
bool visi[200001];
int tcheck[200001];
int parent[200001];
bool cycvisi[200001];
bool check[200001];
vector<Info> edge;
void BFS(vector<vector<int>> list){
    while(!q.empty()){
        pii now = q.front();
        q.pop();
        check[now.first] = true;
        for(int next: list[now.first]){
            if(check[next]) continue;
            if(visi[next]){
                edge.push_back({now.first, next, now.second});
                continue;
            }
            edge.push_back({now.first, next, now.second});
            visi[next] = true;
            q.push({next, now.second + 1});
        }
    }
}

int Find(int x){
    if(parent[x] == x) return x;
    
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    
    if(x!=y) parent[y] = x;
}

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> list(n + 1);
    for(int i = 1;i<=n;i++) parent[i] = i;
    for(int i = 0;i<m;i++){
        int a, b; cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    for(int i = 0;i<k;i++){
        int tk; cin >> tk;
        q.push({tk, 1});
        visi[tk] = true;
    }
    BFS(list);
    sort(edge.begin(), edge.end());
    
    int ans = 0;
    for(int i = 0;i<edge.size();i++){
        Info now = edge[i];
        if(Find(now.x) == Find(now.y)){
            cout << now.t;
            exit(0);
        }
        else Union(now.x, now.y);
    }
}