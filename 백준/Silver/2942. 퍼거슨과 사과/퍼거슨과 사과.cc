#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main(void){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b; cin >> a >> b;
    int k = gcd(a,b);

    for (int i = 1; i <= k; ++i) {
        if (k % i  == 0){
            cout << i << " " << a / i << " " << b / i << "\n";
        }
    }
    return 0;
}