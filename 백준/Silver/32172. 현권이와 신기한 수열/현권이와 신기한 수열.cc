#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<int> arr;
    map<int, int> mp;

    arr.push_back(0);
    mp[0]++;
    for (int i = 1; i <= n; i++) {
        if (arr[i - 1] - i < 0) {
            arr.push_back(arr[i - 1] + i);
            mp[arr[i]]++;
            continue;
        }

        if (mp[arr[i - 1] - i]) {
            arr.push_back(arr[i - 1] + i);
            mp[arr[i]]++;
            continue;
        }

        arr.push_back(arr[i - 1] - i);
        mp[arr[i]]++;
    }
    cout << arr[n];
    return 0;
}