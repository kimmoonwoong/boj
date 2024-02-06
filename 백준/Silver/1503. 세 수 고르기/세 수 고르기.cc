#include <iostream>
#include <vector>
using namespace std;
bool check[1002];
int main() {
    int n, m; cin >> n >> m;
    for(int i = 0;i<m;i++){
        int k; cin >> k;
        check[k] = true;
    }
    vector<int> arr;
    for(int i = 1;i<=1001;i++){
        if(!check[i]) arr.push_back(i);
    }
    int ans = 1e11;
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr.size();j++){
            for(int k = 0;k<arr.size();k++){
                ans = min(ans, abs(n - arr[i] * arr[j] * arr[k]));
                if(arr[i] * arr[j] * arr[k] > n) break;
            }
        }
    }
    cout << ans;
    return 0;
}