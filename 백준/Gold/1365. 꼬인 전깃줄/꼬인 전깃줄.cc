#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int idx = 0;
    for(int i = 0;i<n;i++){
        int k; cin >> k;
        
        if(i == 0) arr[idx++] = k;
        else{
            if(k > arr[idx - 1]) arr[idx++] = k;

            else{
                int cur = lower_bound(arr,arr + idx, k) - arr;
                arr[cur] = k;
            }
        }
    }
    cout << n - idx << "\n";
    return 0;
}