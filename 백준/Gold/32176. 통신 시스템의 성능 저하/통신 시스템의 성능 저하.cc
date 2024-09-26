#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

struct Node {
    int x;
    int y;
    int dist;
};

vector<Node> arr;
int total = 0;
int ans1, ans2;

void DFS(int depth, int currentdepth, int s, vector<int> nodearr, bool check, int p) {
    if (currentdepth == depth) {
        int maxx = 0, maxy = 0, minx = 7, miny = 7;
        if (check) {
            for (int i = 0; i < arr.size(); i++) {
                bool isCheck = false;

                for (int k : nodearr) {
                    if (i == k)
                    {
                        isCheck = true;
                        break;
                    }
                }
                if (isCheck) {
                    continue;
                }

                maxx = max(arr[i].x, maxx);
                maxy = max(arr[i].y, maxy);
                minx = min(arr[i].x, minx);
                miny = min(arr[i].y, miny);
                
            }
            ans1 = max((total - p) - ((maxx - minx + 1) * (maxy - miny + 1)), ans1);
        }
        else {
            for (int i : nodearr) {
                maxx = max(arr[i].x, maxx);
                maxy = max(arr[i].y, maxy);
                minx = min(arr[i].x, minx);
                miny = min(arr[i].y, miny);

            }
            ans2 = max(p - ((maxx - minx + 1) * (maxy - miny + 1)), ans2);
        }
        return;
    }

    for (int i = s; i < arr.size(); i++) {
        nodearr.push_back(i);
        DFS(depth, currentdepth + 1, i + 1, nodearr, check, p + arr[i].dist);
        nodearr.pop_back();
    }
}

int main(void)
{
    int n, m, k1, k2; cin >> n >> m >> k1 >> k2;

    pii start;
    vector<pii> node;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'B')
                start = { i, j };
            else if (s[j] == 'N')
                node.push_back({ i, j });
        }
    }

    for (int i = 0; i < node.size(); i++)
    {
        arr.push_back({ node[i].first, node[i].second, abs(node[i].first - start.first) + abs(node[i].second - start.second) });
        total += arr.back().dist;
    }
    DFS(m - k1, 0, 0, {}, true, 0);
    DFS(k2, 0, 0, {}, false, 0);

    cout << ans1 << "\n" << ans2;
    return 0;
}
