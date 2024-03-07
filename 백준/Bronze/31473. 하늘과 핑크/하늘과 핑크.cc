#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    int sum1 = 0, sum2 = 0;
    for(int i = 0;i<n;i++){
        int k; cin >> k;
        sum1 += k;
    }
    
    for(int i = 0;i<n;i++){
        int k; cin >> k;
        sum2 += k;
    }
    
    cout << sum2 << " " << sum1 << "\n";
}