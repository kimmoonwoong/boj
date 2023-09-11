#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, m, k; cin >> n >> m >> k;
    int ans = 0;
    for(int i = 0;i<n;i++){
        string s; cin >> s;
        int cnt = 0;
        for(int j = 0;j<m;j++){
            if(s[j] == '1' || (s[m - 1] != '1' && j == m - 1)){
                if(s[j] == '0') cnt++;
                if(cnt - k + 1 >= 1){
                    ans += cnt - k + 1;
                }
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
    }        
    cout << ans;

}