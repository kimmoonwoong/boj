#include <iostream>
#include <string>
using namespace std;

char check[5] = {'K', 'O', 'R', 'E', 'A'};

int main(){
    string s; cin >> s;
    int cnt = 0;
    int ans = 0;
    for(char k : s){
        if(cnt == 5) cnt = 0;
        if(k == check[cnt]){
            ans++;
            cnt++;
        } 
    }
    cout << ans;
}