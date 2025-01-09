#include <iostream>
#include <vector>
#define pii pair<int, int>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;

    int s; cin >> s;

    vector<pii> arr(n, {-1, -1});
    vector<pii> marr(m);
    for (int i = 0; i < m; i++) {
        int k, t; cin >> k >> t;

        if (t == 0) {
            arr[k - 1].first = i;
        }
        else {
            arr[k - 1].second = i;
        }

        marr[i] = { k, t };
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (arr[i].first > arr[i].second || arr[i].first == -1) {
            int cnt = 0;
            if (arr[i].first && arr[i].second == -1)
                continue;
            for (int j = arr[i].second + 1; j < m; j++) {
                if (i == marr[j].first - 1)
                    break;
                if (!marr[j].second)
                    cnt++;

                if (cnt >= s) {
                    ans.push_back(i + 1);
                    break;
                }
            }
        }
    }

    if (ans.size() == 0)
    {
        cout << -1;
        return 0;
    }

    for (int answer : ans)
        cout << answer << "\n";
}