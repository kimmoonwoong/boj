#include <iostream>
#include <algorithm>
using namespace std;
int arr[15001];
int main() {
    int n; cin >> n;
    int k; cin >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int start = 0;
    int end = n - 1;
    int ans = 0;
    while (start < end) {
        int sum = arr[start] + arr[end];

        if (sum == k) {
            ans++;
            start++;
            end--;
        }
        else if (sum < k) start++;
        else end--;
    }
    cout << ans;
}