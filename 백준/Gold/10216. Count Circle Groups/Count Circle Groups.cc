#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

struct Node {
    int x;
    int y;
    int r;
};
int parent[3001];
int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    
    parent[y] = x;
}
int main()
{
    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;
        vector<Node> arr(n);
        map<int, int> mp;
        for(int i = 0; i<n;i++) parent[i] = i;
        for(int i = 0;i<n;i++){
            int x, y, r; cin >> x >> y >> r;
            arr[i] = {x, y, r};
        }
        
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                if(i == j) continue;
                if (sqrt(pow(arr[i].x - arr[j].x, 2) + pow(arr[i].y - arr[j].y, 2)) <= arr[i].r + arr[j].r) {
                
                    if(Find(i) != Find(j)){
                       Union(i, j);   
                    }
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            mp[Find(i)]++;
        }
        cout << mp.size() << "\n";
    }
}