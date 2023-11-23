#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    
    vector<int> arr(n);
    
    for(int i = 0;i<n;i++) cin >> arr[i];
    
    int cur = arr[n - 1];
    int ans = 0;
    for(int i = n - 2; i>=0;i--){
        if(arr[i] >= cur){
            ans += (arr[i] - (cur - 1));
            cur = cur - 1;
        }
        else cur = arr[i];
    }
    cout << ans;
}