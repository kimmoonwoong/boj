#include <iostream>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll x, y; cin >> x >> y;
    cout << 2 << "\n";
    cout << x * y - x << "\n";
    cout << -(x * y - y);

}