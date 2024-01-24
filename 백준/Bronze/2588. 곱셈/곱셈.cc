#include <iostream>
using namespace std;
int main() {
    int x, y; cin >> x >> y;
    cout << x * (y % 10) << "\n" << x * ((y % 100) / 10) << "\n" << x *(y / 100) << "\n" << x * y;
    return 0;
}