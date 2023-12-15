#include <iostream>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int lv; string s; cin >> lv >> s;
    int k = 0;
    if(s == "bad") k = 200;
    else if(s == "cool") k = 400;
    else if(s == "great") k = 600;
    else if(s == "perfect") k = 1000;
    cout << lv * k;
}