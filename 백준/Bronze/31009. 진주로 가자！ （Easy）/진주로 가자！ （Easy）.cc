#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> arr;
    int ans1, ans2 = 0;
    for (int i = 0; i < n; i++) {
        string s; int k; cin >> s >> k;
        if (s == "jinju")
            ans1 = k;
        else arr.push_back(k);
    }
    for (int k : arr) if (ans1 < k) ans2++;
    cout << ans1 << "\n" << ans2;
}