#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>

using namespace std;

bool cmp1(pii o1, pii o2)
{
    if (o1.first == o2.first) return o1.second < o2.second;
    return o1.first > o2.first;
}
bool cmp2(pii o1, pii o2) {
    if (o1.first == o2.first) return o1.second > o2.second;
    return o1.first < o2.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<pii> arr1(n);
    vector<pii> arr2(n);
    for (int i = 0; i < n; i++) {
        int q, p; cin >> q >> p;

        arr1[i] = { q, p };
        arr2[i] = { p, q };
    }

    sort(arr1.begin(), arr1.end(), cmp1);
    sort(arr2.begin(), arr2.end(), cmp2);

    cout << arr1[0].first << " " << arr1[0].second << " " << arr1[1].first << " " << arr1[1].second << "\n";
    cout << arr2[0].second << " " << arr2[0].first << " " << arr2[1].second << " " << arr2[1].first;

}