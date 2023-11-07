#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, l; cin >> n >> l; 
    map<int, int> mp;
    for(int i = 0;i<n;i++){
        string s; cin >> s;
        int cnt = 0;
        for(int j =0;j<l - 1;j++){
            if(s[j] == '1' && s[j + 1] == '0')
                cnt++;
        }
        if(s[l - 1] == '1') cnt++;
        mp[cnt]++;
    }
    
    int size = mp.size();
    int cnt = 0;
    for(auto nw : mp){
        if(cnt == size - 1){
            cout << nw.first << " " << nw.second;
        }
        cnt++;
    }
}