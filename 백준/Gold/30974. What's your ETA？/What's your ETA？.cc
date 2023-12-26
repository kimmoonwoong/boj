#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
#define pii pair<long long, long long>
#define ll long long
using namespace std;
ll INF = LLONG_MAX;
bool check[10000001];
int d[400001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 2;i<=sqrt(10000000);i++){
        if(check[i]) continue;
        for(int j = i * i; j<=10000000;j+=i){
            check[j] = true;
        }
    }
    
    int n, m; cin >> n >> m;
    int maxs = 0;
    vector<vector<pii>> list(n + 1);
    for(int i = 1;i<=n;i++) cin >> d[i];
    for(int i = 0;i<m;i++){
        ll a, b, c; cin >> a >> b >> c;
        if(check[d[a] + d[b]]) continue;
        list[a].push_back({b, c});
        list[b].push_back({a, c});
    }
    vector<ll> w(n + 1, INF);
    priority_queue<pii> pq;
    w[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        pii now = pq.top();
        pq.pop();
        if(w[now.second] < -now.first) continue;
        for(pii next: list[now.second]){
            ll dist = -now.first + next.second;
            if(w[next.first] > dist){
                w[next.first] = dist;
                pq.push({-dist, next.first});
            }
        }
    }
    
    if(w[n] == INF) cout << "Now where are you?";
    else cout << w[n];
}