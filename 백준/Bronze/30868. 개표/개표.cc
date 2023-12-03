#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s = "++++";
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        for (int j = 0; j < k / 5; j++) {
            cout << s << " ";
        }
        for (int j = 0; j < k % 5; j++) {
            cout << "|";
        }
        cout << "\n";
    }
}