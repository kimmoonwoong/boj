#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> arr(n + 1);
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            arr[l] = i;
            l++;
        }
        else {
            arr[r] = i;
            r--;
        }
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
}