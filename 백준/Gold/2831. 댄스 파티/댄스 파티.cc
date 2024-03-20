#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> menA, menB;
    vector<int> womA, womB;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k < 0) menB.push_back(abs(k));
        else menA.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k < 0) womB.push_back(abs(k));
        else womA.push_back(k);
    }
    sort(menA.begin(), menA.end());
    sort(menB.begin(), menB.end());
    sort(womA.begin(), womA.end());
    sort(womB.begin(), womB.end());
    int a = 0, b = 0;
    int ans = 0;
    while (a < menA.size() && b < womB.size()) {
        if (menA[a] < womB[b]) {
            ans++;
            a++;
            b++;
        }
        else {
            b++;
        }
    }
    a = 0, b = 0;
    while (a < menB.size() && b < womA.size()) {
        if (menB[a] > womA[b]) {
            ans++;
            a++;
            b++;
        }
        else {
            a++;
        }
    }
    cout << ans;


    return 0;
}