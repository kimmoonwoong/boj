#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    
    long long ans = 1;
    
    for(int i = n;i>0;i-=2){
        ans *= (i * (i - 1)) / 2;
        
        ans /= (i / 2);
    }
    cout << ans;
    return 0;
}