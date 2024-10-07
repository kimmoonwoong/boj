#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int x;
    int y;
    int v;
    int p;
};

queue<Node> q;
vector<int> ans;
Node arr[3001];
bool visi[3001];
int n, k, t;
void BFS() {
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (visi[i])
                continue;
            if (sqrt(pow(arr[i].x - now.x, 2) + pow(arr[i].y - now.y, 2)) <= k && abs(now.v - arr[i].v) <= t) {
                if (arr[i].p) {
                    ans.push_back(i + 1);
                }
                visi[i] = true;
                q.push(arr[i]);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k >> t;

    int x, y, v; cin >> x >> y >> v;


    for (int i = 0; i < n; i++) {
        int xx, yy, vv, p; cin >> xx >> yy >> vv >> p;

        arr[i] = { xx, yy, vv, p };
    }

    for (int i = 0; i < n; i++) {
        if (sqrt(pow(arr[i].x - x, 2) + pow(arr[i].y - y, 2)) <= k && abs(v - arr[i].v) <= t) {
            q.push(arr[i]);
            visi[i] = true;
            if (arr[i].p)
                ans.push_back(i + 1);
        }
    }
    BFS();
    if (ans.size() == 0)
        cout << 0;

    sort(ans.begin(), ans.end());
    for (int a : ans)
        cout << a << " ";
    return 0;
}