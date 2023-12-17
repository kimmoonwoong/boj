#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define pii pair<int, int>
#define ll long long
using namespace std;

    
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    string ans;
    int cnt;
    map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
    }
    cnt = mp['B'];
    ans = "B";
    if (cnt < mp['S']) {
        ans = "S";
        cnt = mp['S'];
    }
    else if (cnt == mp['S']) ans += "S";
    if (cnt < mp['A']) ans = "A";
    else if(cnt == mp['A']) ans += "A";
    if (ans == "BSA") cout << "SCU";
    else cout << ans;
    return 0;
}