#include <iostream>
#include <cmath>
using namespace std;

int arr[100001];

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    int n, s; cin >> n >> s;
    
    for(int i = 0;i<n;i++){
        int k; cin >> k;
        arr[i] = abs(s - k);
    }
    
    int ans = gcd(arr[0], arr[1]);
    
    for(int i = 2;i<n;i++){
        ans = gcd(ans, arr[i]);
    }
    cout << ans;
}