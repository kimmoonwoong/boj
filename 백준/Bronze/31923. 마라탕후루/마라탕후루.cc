#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    int n, p, q; cin >> n >> p >> q;
    vector<int> arrA(n);
    vector<int> arrB(n);

    for (int i = 0; i < n; i++)
        cin >> arrA[i];
    for (int i = 0; i < n; i++)
        cin >> arrB[i];

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (p == q) {
            if (arrA[i] == arrB[i]) {
                ans[i] = 0;
            }
        }
        else if (p > q) {
            if (arrA[i] <= arrB[i] && (arrB[i] - arrA[i]) % (p - q) == 0)
                ans[i] = (arrB[i] - arrA[i]) / (p - q);
        }
        else {
            if (arrB[i] <= arrA[i] && (arrA[i] - arrB[i]) % (q - p) == 0)
                ans[i] = (arrA[i] - arrB[i]) / (q - p);
        }

        if (ans[i] == -1) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}
