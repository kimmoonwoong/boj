#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;

int m1[1001][1001];
int m2[10][10];
int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, r, c; cin >> n >> m >> r >> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> m1[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m2[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + r <= n && j + c <= m) {
                int mins = 10;
                int maxs = -99;

                for (int k = 0; k < r; k++) {
                    for (int p = 0; p < c; p++) {
                        int t = m1[i + k][j + p] - m2[k][p];
                        mins = min(mins, t);
                        maxs = max(maxs, t);
                    }
                }

                if (mins == maxs)
                    ans++;
            }
        }
    }

    cout << ans;
    return 0;
}
