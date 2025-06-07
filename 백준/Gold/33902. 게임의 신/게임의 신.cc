#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, y;
    cin >> x >> y;
    vector<bool> arr(y + 1);
    
    arr[y] = true;

    for (int i = y - 1; i >= x; i--) {
        for (int j = i + 1; j <= y; j++) {
            if (gcd(i, j) == 1) {
                arr[i] = arr[i] || arr[j];
            }
        }
        arr[i] = !arr[i];
    }
    cout << (arr[x] ? "putdata" : "khj20006");
    

    return 0;
}
