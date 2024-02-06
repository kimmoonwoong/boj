#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


int main() {
    int k; cin >> k;
    int digit = 0;
    int num = 1;
    int i = 1;
    bool check = false;
    while(k >= num){
        num += pow(2,i);
        digit++;
        check = true;
        i++;
    }
    string ans;
    for(int i = 0;i<digit;i++) ans += "4";
    num -= pow(2, i - 1);
    int cur = k - num;
    
    for(int i = digit - 1;i>=0;i--){
        if(cur % 2 != 0) ans[i] = '7';
        cur /= 2;
    }
    cout << ans;
    return 0;
}