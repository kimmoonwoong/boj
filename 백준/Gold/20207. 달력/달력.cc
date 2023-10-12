#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt[366];
pair<int, int> arr[1001];

bool cmp(pair<int, int> o1, pair<int, int> o2) {
    if (o1.first == o2.first) return o1.second > o2.second;
    return o1.first < o2.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        arr[i] = { s, e };
    }

    sort(arr, arr + n, cmp);
    
    for (int i = 0; i < n;i++) {
        for (int j = arr[i].first; j <= arr[i].second; j++) cnt[j]++;
    }
    int ans = 0;
    int w = 0;
    int h = 0;
    for (int i = 0; i <= 365; i++) {
        if (cnt[i] == 0 || i == 365) {
            if (i == 365 && cnt[i] != 0) {
                w++;
                h = max(h, cnt[i]);
            }
            ans += w * h;
            w = 0, h = 0;
        }
        else {
            w++;
            h = max(h, cnt[i]);
        }

    }
    cout << ans;
  
}