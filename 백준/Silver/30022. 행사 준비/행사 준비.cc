#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visi[2][100001];

bool cmp(pair<long long, int> o1, pair<long long, int> o2) {
    return o1.first > o2.first;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a, b; cin >> n >> a >> b;
    vector<int> arrA(n);
    vector<int> arrB(n);
    vector < pair<long long, int>> dist(n);
    for (int i = 0; i < n; i++) {
        int p, q; cin >> p >> q;
        arrA[i] = p;
        arrB[i] = q;
        dist[i] = { abs(p - q), i };
    }
    sort(dist.begin(), dist.end(), cmp);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (arrA[dist[i].second] > arrB[dist[i].second]) {
            if (b > 0) {
                ans += arrB[dist[i].second];
                b--;
            }
            else {
                ans += arrA[dist[i].second];
                a--;
            }
        }
        else {
            if (a > 0) {
                ans += arrA[dist[i].second];
                a--;
            }
            else {
                ans += arrB[dist[i].second];
                b--;
            }
        }
    }
    cout << ans;

}