#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string ans = "";
    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'x' || s[j] == 'X') {
                ans += t[j];
            }
        }
    }

    transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
    cout << ans;
}