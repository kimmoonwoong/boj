#include <iostream>
#include <vector>
#define pii pair<int, int>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;

    cout << "SN " << n;

    if (m <= 26) {
        char c = 'A' + m - 1;
        cout << c;
    }
    else {
        int k = (m - 1) / 26;
        int k2 = ((m - 1) % 26) + 1;
        char k3 = 'a' + k2 - 1;
        char c = 'a' + k - 1;
        cout << c << k3;
    }
}