#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m; cin >> n >> m;
    if(n % 2 != 0 && m %2 != 0) cout << n * m - 1;
    else cout << n * m;
    return 0;
}