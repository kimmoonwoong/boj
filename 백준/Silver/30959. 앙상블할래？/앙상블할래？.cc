#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define pii pair<int, int>
#define ll long long
using namespace std;

int maxs = 0;
int n, m;
int ans[101];
void Back(vector<vector<int>> arr, int cur, vector<pii> cnt, int select) {
    for (int i = cur; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) cnt[j].second++;
            else cnt[j].first++;
        }
        if (select % 2 != 0) {
            int curcnt = 0;
            for (int i = 0; i < m; i++) {
                if (cnt[i].first > cnt[i].second) {
                    if (ans[i] == 0) curcnt++;
                }
                else {
                    if (ans[i] == 1) curcnt++;
                }
            }
            if (maxs < curcnt) {
                cout << 1;
                exit(0);
            }
        }
        Back(arr, i + 1, cnt, select + 1);
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) cnt[j].second--;
            else cnt[j].first--;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < m; i++) cin >> ans[i];
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == ans[j]) cnt++;
        }
        maxs = max(maxs, cnt);
    }
    vector<pii> cnt(m);
    Back(arr, 0, cnt, 1);
    cout << 0;
    return 0;
}