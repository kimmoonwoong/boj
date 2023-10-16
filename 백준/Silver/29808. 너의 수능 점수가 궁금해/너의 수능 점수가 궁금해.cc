#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long arr[5];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int s; cin >> s;

    if (s % 4763 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    s /= 4763;
    vector<pair<int, int>> ans;
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            if (i * 508 + j * 212 == s) {
                ans.push_back({ i, j });
            }
            else if (i * 508 + j * 305 == s) ans.push_back({ i, j });
            else if (i * 108 + j * 212 == s) ans.push_back({ i, j });
            else if (i * 108 + j * 305 == s) ans.push_back({ i, j });
        }
    }

    if (ans.size() == 0) cout << 0;
    else {
        cout << ans.size() << "\n";
        for (pair<int, int> a : ans) cout << a.first << " " << a.second << "\n";
    }
}