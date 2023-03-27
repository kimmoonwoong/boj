#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int t1, t2; cin >> t1 >> t2;
    int sum = (t1 / 2) + t2;
    
    if(sum > n) cout << n;
    else cout << sum;
}