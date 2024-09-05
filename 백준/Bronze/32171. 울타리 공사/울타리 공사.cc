#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int n; cin >> n;
    int maxx = -11, maxy = -11;
    int minx = 11, miny = 11;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        maxx = max({ maxx, x2 });
        maxy = max({ maxy, y2 });
        minx = min(minx, x1);
        miny = min(miny, y1);

        int x = abs(maxx - minx);
        int y = abs(maxy - miny);
        cout << (x + y) * 2 << "\n";
    }
    return 0;
}