#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ll long long
using namespace std;

struct Edge {
    int next, value, g, k;
    bool operator<(const Edge &d) const{
        return value < d.value;
    }
};
int INF = 2e9;
void Dekkers(vector<vector<Edge>> list, int k) {
    priority_queue<Edge> pq;
    vector<int> w(list.size(), INF);
    w[1] = 0;
    pq.push({ 1, 0, 0, k });

    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        if (w[now.next] < now.value) {
            continue;
        }

        for (Edge next : list[now.next]) {
            if (now.value %  next.g == 0) {
                if (w[next.next] > w[now.next] + next.value) {
                    w[next.next] = w[now.next] + next.value;
                    pq.push({ next.next, w[next.next], 0, now.k });
                    continue;
                }
            }

            if (now.k > 0) {
                if (w[next.next] > w[now.next] + next.value) {
                    w[next.next] = w[now.next] + next.value;
                    pq.push({ next.next, w[next.next], 0, now.k - 1 });
                }
            }
            if (w[next.next] > next.value + (now.value / next.g) * next.g + next.g) {
                w[next.next] = next.value + (now.value / next.g) * next.g + next.g;
                pq.push({ next.next, w[next.next], 0, now.k });
            }
        }
    }

    if (w[list.size() - 1] == INF) cout << -1;
    else cout << w[list.size() - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;

    vector<vector<Edge>> list(n + 1);

    for (int i = 0; i < m; i++) {
        int s, e, t, g; cin >> s >> e >> t >> g;
        list[s].push_back({ e, t, g, 0});
    }

    Dekkers(list, k);
}