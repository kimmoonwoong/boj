#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[100001];
bool visi[100001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    int e = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        while (e < n) {
            if (visi[arr[e]]) break;
            visi[arr[e]] = true;
            e++;
        }
        ans += (long long)(e - i);
        visi[arr[i]] = false;
    }
    cout << ans;
}