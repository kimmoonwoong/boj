#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int n; cin >> n;
    vector<pair<int, int>> arr(n + 1);
    for(int i = 0;i<n;i++){
        int s,e; cin >> s >> e;
        arr[i] = {s, e};
    }
    int ans = 0;
    vector<pair<int, int>> srt;
    int dis = 0;
    for(int i = 0;i<n - 1;i++){
        ans += abs(arr[i].first - arr[i + 1].first) + abs(arr[i].second - arr[i + 1].second);

        int atob = abs(arr[i].first - arr[i + 1].first) + abs(arr[i].second - arr[i + 1].second);
        int btoc = abs(arr[i + 1].first - arr[i + 2].first) + abs(arr[i + 1].second - arr[i + 2].second);
        int atoc = abs(arr[i].first - arr[i + 2].first) + abs(arr[i].second - arr[i + 2].second);
        dis = max(dis, atob + btoc - atoc);
    }
    ans -= dis;
    cout << ans;
}