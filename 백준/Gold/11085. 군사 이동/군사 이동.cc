#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
    int a;
    int b;
    int c;
};

bool cmp(Edge o1, Edge o2){
    return o1.c > o2.c;
}

Edge arr[50001];
int parent[1001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    
    if(x !=y) parent[x] = y;
}

int main() {
    
    int p, w; cin >> p >> w;
    for(int i = 1;i<=p;i++)
    {
        parent[i] = i;
    }
    int s, e; cin >> s >> e;
    
    
    for(int i = 0;i<w;i++){
        int a, b, c; cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }
    
    sort(arr, arr + w, cmp);
    
    for(int i = 0;i<w;i++){
        if(Find(arr[i].a) != Find(arr[i].b)){
            Union(arr[i].a, arr[i].b);
        }
        if(Find(s) == Find(e)){
            cout << arr[i].c;
            break;
        }
    }
    
    return 0;
}