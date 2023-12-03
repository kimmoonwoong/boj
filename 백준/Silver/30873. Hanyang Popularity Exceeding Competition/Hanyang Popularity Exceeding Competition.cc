#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int p, c; cin >> p >> c;
        if (abs(p - k) <= c) {
            k++;
        }
    }
    cout << k;
    
}