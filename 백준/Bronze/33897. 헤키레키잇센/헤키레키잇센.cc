#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;



int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int curr = -1;
    int c = 1;
    int count = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;

        if (curr == -1)
            curr = k;
        else {
            if (k >= curr)
            {
                c++;
            }
            else {
                sum++;
                count = max(c, count);
                c = 1;
            }
            curr = k;
        }
    }

    sum++;
    count = max(c, count);
    cout << sum << " " << count;
    return 0;
}
