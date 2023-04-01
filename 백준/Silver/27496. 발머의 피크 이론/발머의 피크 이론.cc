#include <iostream>

using namespace std;
int arr[1010001];
int main(){
    int n,l; cin >> n >> l;

    for(int i = 1;i<=n;i++){
        int c; cin >> c;
        arr[i] += (c + arr[i - 1]); arr[i + l] -= c;
    }
    int ans = 0;
    for(int i = 1; i<=n;i++){
        if(arr[i] >= 129 && arr[i] <= 138) ans++;
    }
    cout << ans;
}