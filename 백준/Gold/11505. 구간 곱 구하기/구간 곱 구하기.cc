#include <iostream>

using namespace std;
long long *tree;
long long arr[1000001];
long long mod = 1000000007;
long long init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % mod;
}

long long sum(int start, int end, int node, int left, int right){
    if(end < left || start > right) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return (sum(start, mid, node * 2, left, right) * sum(mid + 1, end, node * 2 + 1, left, right)) % mod;
}

long long update(int start, int end, int node, int idx, long long dif){
    if(idx < start || idx > end) return tree[node];
    if(start == end) return tree[node] = dif;
    int mid = (start + end) / 2;
    return tree[node] =
    (update(start, mid, node * 2, idx, dif) *
    update(mid + 1, end, node * 2 + 1, idx, dif)) % mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    
    for(int i = 0;i<n;i++) cin >> arr[i];
    
    tree = new long long[n * 4];
    init(0, n -1, 1);
    for(int i = 0;i<m + k;i++){
        int a, b; long long c; cin >> a >> b >> c;
        if(a == 1){
            update(0, n - 1, 1, b - 1, c);
        }
        else cout << sum(0, n-1, 1, b -1, c- 1) << "\n";
    }
}