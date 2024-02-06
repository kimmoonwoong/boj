#include <iostream>
#include <string>

using namespace std;
int arr[200001];
int main() {
    int n; cin >> n;
    for(int i = 0;i<n;i++) cin >> arr[i];
    
    long long ans = n;
    int cur = arr[0];
    long long plus = 1;
    for(int i = 1;i<n;i++){
        if(cur < arr[i]){
            ans += plus;
            cur = arr[i];
            plus++;
        }
        else{
            plus = 1;
            cur = arr[i];
        }
    }
    cout << ans;
    return 0;
}