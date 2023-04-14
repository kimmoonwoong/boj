#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int k; cin >> k;
    long long a,b,c,d; cin >> a >> b >> c >> d;
    long long r1 = a * k + b;
    long long r2 = c * k + d;
    if (r1 == r2) cout << "Yes " << r1;
    else cout << "No";
    return 0;
}   