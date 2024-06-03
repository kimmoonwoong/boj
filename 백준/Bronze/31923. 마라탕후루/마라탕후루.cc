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

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (p == q) {
            if (arrA[i] == arrB[i]) {
                ans[i] = 0;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        else if (p > q) {
            if (arrA[i] > arrB[i] || (arrB[i] - arrA[i]) % (p - q)) {
                cout << "NO";
                return 0;
            }
            else {
                ans[i] = (arrB[i] - arrA[i]) / (p - q);
            }
        }
        else {
            if (arrB[i] > arrA[i] || (arrA[i] - arrB[i]) % (q - p)) {
                cout << "NO\n";
                return 0;
            }
            else {
                ans[i] = (arrA[i] - arrB[i]) / (q - p);
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}
