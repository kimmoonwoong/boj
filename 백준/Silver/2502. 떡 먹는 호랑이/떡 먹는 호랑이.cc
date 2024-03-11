#include <iostream>

using namespace std;

int a[41];
int b[41];
int main() {
    int d, k; cin >> d >> k;
    
    a[1] = 1;b[1] = 0;
    a[2] = 0;b[2] = 1;
    
    for(int i = 3;i<=40;i++){
        a[i] = a[i -1] + a[i - 2];
        b[i] = b[i -1] + b[i - 2];
    }
    
    for(int i = 1;i<=k;i++){
        int n = k - (a[d] * i); 
        if(n % b[d] == 0){
            cout << i << "\n"; 
            cout << n / b[d];
            break;
        }
    }
}