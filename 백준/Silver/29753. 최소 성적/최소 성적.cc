#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int arr[9] = { 0, 100, 150, 200, 250, 300, 350, 400, 450 };
int ans[9];
string carr[9] = { "F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; double x; cin >> n >> x;
    int xs = round(x * 100);
    int gsum = 0; int csum = 0;
    int ci = 0;
    for (int i = 0; i < n; i++)
    {
        int c; string s;
        if (i == n - 1) {
            cin >> c;
            ci = c;
            csum += c;
            continue;
        }
        else cin >> c >> s;
        if (s == "A+") gsum += (450 * c);
        else if (s == "A0") gsum += (400 * c);
        else if (s == "B+") gsum += (350 * c);
        else if (s == "B0") gsum += (300 * c);
        else if (s == "C+") gsum += (250 * c);
        else if (s == "C0") gsum += (200 * c);
        else if (s == "D+") gsum += (150 * c);
        else if (s == "D0") gsum += (100 * c);

        csum += c;
    }

    for (int i = 0; i < 9; i++) {
        int k = gsum + ci * arr[i];
        ans[i] = k / csum;
    }
    int idx = upper_bound(ans, ans + 9, xs) - ans;
    if (idx == 9) cout << "impossible";
    else cout << carr[idx];
}