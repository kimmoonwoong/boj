#include <iostream>
#include <cmath>
using namespace std;
long long arr[5];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 0; i < t; i++) cin >> arr[i];

    long long ans = 0;

    ans += arr[0] > arr[2] ? abs(arr[0] - arr[2]) * 508 : abs(arr[0] - arr[2]) * 108;
    ans += arr[1] > arr[3] ? abs(arr[1] - arr[3]) * 212 : abs(arr[1] - arr[3]) * 305;
    ans += arr[4] * 707;
    ans *= 4763;
    cout << ans;

}