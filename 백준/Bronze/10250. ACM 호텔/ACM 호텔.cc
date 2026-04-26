#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int h, w, n; cin >> h >> w >> n;

        if(n % h == 0)
            cout << h * 100 + (n / h) << "\n";
        else
            cout << n % h * 100 + (n / h  + 1) << "\n";
    }
}