#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> mp;
    
    for(int i = 0;i<10;i++){
        int k; cin >> k;
        mp[k % 42]++;
    }
    cout << mp.size();
}