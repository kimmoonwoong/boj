#include <iostream>
#include <map>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b; cin >> a >> b;
    
    int k = a - b;
    if (k > 0 && b >= k) {
        cout << "YES\n";
        cout << (k - 1) + 1 << "\n";

        for (int i = 0; i < k - 1; i++) cout << "aba\n";
        for (int i = 0; i < (b - k) + 1; i++) cout << "ab";
        cout << "a";
    }
    else cout << "NO";
}