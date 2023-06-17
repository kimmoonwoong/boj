#include <iostream>

using namespace std;

int main(){
    long long n; cin >> n;
    long long ans = 0;
    for(int i = 1;i<=n;i++)ans += (long long)(n / i) * i;
    cout << ans;
}