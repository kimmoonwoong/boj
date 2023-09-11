#include <iostream>
#include <string>
using namespace std;
char arr[16];
int main(){
    string s = "WelcomeToSMUPC";
    for(int i = 0;i<=s.length();i++){
        arr[i + 1] = s[i];
    }
    int n; cin >> n;
    if(n%14 == 0) cout << arr[14];
    else cout << arr[n % 14];
}