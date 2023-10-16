#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    queue<pair<string, int>> q;
    for (int i = 0; i < n; i++) {
        string s; int k; cin >> s >> k;
        q.push({ s, k });
    }

    while (q.size() > 1) {
        pair<string, int> now = q.front();
        q.pop();

        for (int i = 0; i < now.second - 1; i++) {
            pair<string, int> k = q.front();
            q.pop();
            q.push(k);
        }
        q.pop();
    }
    cout << q.front().first;
}