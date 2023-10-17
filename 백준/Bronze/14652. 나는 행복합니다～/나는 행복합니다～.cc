#include <iostream>

using namespace std;

int main(){
    int a, b, c; cin >> a >> b >> c;
    for(int i = 0;i<a;i++){
        for(int j = 0;j<b;j++){
            if(i * b + j == c){
                cout << i << " " << j;
                return 0;
            }
        }
    }
}