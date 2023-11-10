#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pii pair<int, int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    
    for(int i = 0;i<n;i++) cin >> A[i];
    for(int i = 0;i<n;i++) cin >> B[i];
    
    vector<int> dist(n);
    for(int i = 0;i<n;i++) dist[i] = A[i] - B[i];
    
    for(int i = 1;i<n;i++){
        if(dist[i] > dist[i - 1]) dist[i] = dist[ i -1];
    }
    for(int i = 0;i<n;i++) dist[i] *= -1;
    int q; cin >> q;
    for(int i = 0;i<q;i++){
        int size; cin >> size;
        size *= -1;
        int ans = upper_bound(dist.begin(), dist.end(), size) - dist.begin();
        cout << ans << "\n";
    }
    return 0;
}