#include <iostream>
using namespace std;
int main(void)
{
    int a, p, c; cin >> a >> p >> c;

    cout << max(a + c, p);

    return 0;
}
