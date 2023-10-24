// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    int n; cin >> n;
    vector<string> map(n);
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != '.') {
                for (int k = i - 1; k < (i - 1) + 3; k++) {
                    for (int p = j - 1; p < (j - 1) + 3; p++) {
                        if (k < 0 || k >= n || p < 0 || p >= n) continue;
                        if (k == i && p == j) {
                            ans[k][p] = -1;
                            continue;
                        }
                        if (map[k][p] != '.') continue;
                        ans[k][p] += map[i][j] - '0';
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] == -1) cout << "*";
            else if (ans[i][j] >= 10) cout << "M";
            else cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}