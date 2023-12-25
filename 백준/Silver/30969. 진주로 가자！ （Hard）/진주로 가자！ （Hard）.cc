#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> arr(1001);
    int ans1, ans2 = 0;
    for (int i = 0; i < n; i++) {
        string s; long long k; cin >> s >> k;
        if (s == "jinju")
            ans1 = k;
        else {
            if (k > 1000) ans2++;
            else arr[k]++;
        }
    }
    for (int i = ans1 + 1; i <= 1000; i++) ans2 += arr[i];
    cout << ans1 << "\n" << ans2;
}