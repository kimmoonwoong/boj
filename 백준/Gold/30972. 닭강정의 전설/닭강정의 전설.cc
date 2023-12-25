#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];

    for (int i = 1; i <= n; i++) for (int j = 2; j <= n; j++) arr[i][j] += arr[i][j - 1];

    for (int i = 1; i < n; i++) for (int j = 1; j <= n; j++) arr[i + 1][j] += arr[i][j];
    
    int q; cin >> q;
    
    for (int i = 0; i < q; i++) {
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        int other = 0;
        int sum = 0;
        sum = arr[x2 - 1][y2 - 1] - arr[x2 - 1][y1] - arr[x1][y2 - 1] + arr[x1][y1];
        other= arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1];
        cout << sum * 2 - other << "\n";
    }
}