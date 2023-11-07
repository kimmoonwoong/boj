#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, l; cin >> n >> l;
    
    if(n == 0){
        for(int i = 0;i< l-1;i++) cout << "1";
        cout << "0";
    }
    else{
        cout << n;
        for(int i = 0;i<l-1;i++) cout << "1";
    }
}