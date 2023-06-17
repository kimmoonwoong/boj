#include <iostream>
#include <string>

using namespace std;

int main(){
    string s; cin >> s;
    int n; cin >> n;
    
    cout << s.substr(n - 1, 1);
}