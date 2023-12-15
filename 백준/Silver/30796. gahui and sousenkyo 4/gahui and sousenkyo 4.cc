#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v, k; cin >> v >> k;
    vector<bool> check(v + k);
    vector<int> ans;
    for(int i = v; i>=1;i--){
        if(check[i + k]) continue;
        check[i] = true;
        ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(int n : ans) cout << n <<"\n";
}