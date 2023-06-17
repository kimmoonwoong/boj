#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n; cin >> n;
    long long ans;
    
    ans = sqrt(n);
    
    if(pow(ans, 2) < n) ans++;
    cout << ans;
    
}