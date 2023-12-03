#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        arr[i] = { y, x };
    }
    sort(arr.begin(), arr.end());
    cout << arr[0].second << " " << arr[0].first;
}