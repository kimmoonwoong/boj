#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int ans = 0;
    int idx = n;
    for(int i = n -1; i>=0;i--){
        if(arr[i] == idx) idx--;
        else ans++;
    }
    cout << ans;
    return 0;
}