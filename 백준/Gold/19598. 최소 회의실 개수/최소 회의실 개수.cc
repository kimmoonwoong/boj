#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int n; cin >> n;
    vector<pair<long long, long long>> arr(n);
    for (int i = 0; i < n; i++) {
        long long s, e; cin >> s >> e;
        arr[i] = { s, e };
    }
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    sort(arr.begin(), arr.end());
    pq.push(arr[0].second);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        while (!pq.empty()) {
            if (pq.top() <= arr[i].first) pq.pop();
            else break;
        }
        pq.push(arr[i].second);
        int size = pq.size();
        ans = max(ans, size);
    }
    cout << ans;
    return 0;
}