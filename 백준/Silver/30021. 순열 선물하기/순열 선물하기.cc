#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    if (n == 1) {
        cout << "YES\n";
        cout << 1;
    }
    else if (n == 2) cout << "NO";
    else {
        cout << "YES\n";
        cout << "1 3 2 ";
        for (int i = 4; i <= n; i++) cout << i << " ";
    }
}