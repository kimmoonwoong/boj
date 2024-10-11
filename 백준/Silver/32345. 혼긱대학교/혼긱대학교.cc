#include <iostream>
#include <string>
#define ll long long
using namespace std;

ll mod = 1e9 + 7;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        ll ans = -1;
        ll k = -1;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                if (k == -1)
                {
                    k = 0;
                    ans = 1;
                }
                else {
                    ans = ((k + 1) * ans) % mod;
                    k = 0;
                }
            }
            else {
                if (k != -1)
                    k++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
