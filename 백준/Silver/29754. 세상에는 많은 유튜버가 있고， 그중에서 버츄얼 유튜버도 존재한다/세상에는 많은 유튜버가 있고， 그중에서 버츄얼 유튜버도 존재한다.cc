#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    map<string, int> mp;
    map<string, int> mps;
    int count = 0;
    vector<vector<int>> dayarr;
    vector<vector<int>> timearr;
    for (int i = 0; i < n; i++) {
        string name, start, end; int day; cin >> name >> day >> start >> end;
        int s = (stoi(start.substr(0, 2)) * 60) + stoi(start.substr(3, 2));
        int e = (stoi(end.substr(0, 2)) * 60) + stoi(end.substr(3, 2));
        int diff = e - s;
        day -= 1;
        if (mp.count(name) == 0) {
            mp[name] = count;
            count++;
            dayarr.push_back(vector<int>(m / 7));
            timearr.push_back(vector<int>(m / 7));
        }
        int idx = mp[name];
        dayarr[idx][day / 7]++;
        timearr[idx][day / 7] += diff;
    }
    vector<string> ans;
    int cnt = 0;
    for (auto i : mp) {
        bool isCheck = false;
        for (int j = 0; j < m / 7; j++) {
            if (dayarr[i.second][j] < 5 || timearr[i.second][j] < 60 * 60) {
                isCheck = true;
                break;
            }
        }
        if (!isCheck) {
            cout << i.first << "\n";
            cnt++;
        }
    }
    if (cnt == 0) cout << -1;
}