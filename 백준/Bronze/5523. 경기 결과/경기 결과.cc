#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int a = 0, b = 0;
    
    for(int i = 0;i<n;i++){
        int a1, b1; cin >> a1 >> b1;
        if(a1 > b1) a++;
        else if(b1 > a1) b++;
    }
    cout << a << " " << b;
}