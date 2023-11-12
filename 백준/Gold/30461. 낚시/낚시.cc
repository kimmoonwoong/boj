#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> map(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> map[i][j];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            map[j][i] += map[j - 1][i];
        }
    }

    for (int c = 1; c <= n; c++) {
        int i = c;
        int j = 1;
        while (i <= n && j <= m) {
            map[i][j] += map[i - 1][j - 1];
            i++, j++;
        }
    }
    for (int c = 2; c <= m; c++) {
        int i = 1;
        int j = c;
        while (i <= n && j <= m) {
            map[i][j] += map[i - 1][j - 1];
            i++, j++;
        }
    }

    for (int i = 0; i < q; i++) {
        int w, p; cin >> w >> p;
        cout << map[w][p] << "\n";
    }
}