#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<ll, ll>
#define ll long long
using namespace std;
int parent[100001];
int sum[100001];
bool check[100001];
int Find(int x){
    if(parent[x] == x) return x;
    
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    
    if(x!=y){
        parent[x] = y;
        sum[y] += sum[x];
    }
}

int main() {
    int n, m; cin >> n >> m;
    
    for(int i = 1;i<=100000;i++){
        parent[i] = i;
        sum[i] = 1;
    }
    
    for(int i = 0;i<m;i++){
        int x, y; cin >> x >> y;
        
        if(Find(x) != Find(y)){
            Union(x, y);
        }
    }
    
    int c, h, k; cin >> c >> h >> k;
    int ans = sum[Find(c)];
    int non = Find(h);
    check[non] = true;
    check[Find(c)] = true;
    for(int i = 0;i<k;i++){
        int cnt = 0;
        int cur = 0;
        for(int i = 1;i<=n;i++){
            int k = Find(i);
            if(check[k]) continue;
            if(cnt < sum[k]){
                cnt = sum[k];
                cur = k;
            }
        }
        ans += cnt;
        check[cur] = true;
    }
    cout << ans;
    return 0;
}