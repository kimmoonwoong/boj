#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#define pii pair<int, int>
#define ll long long
using namespace std;

int arrA[101];
int arrB[101];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    map<int, int> mpA;
    map<int, int> mpB;
    for (int i = 0; i < n; i++) {
        cin >> arrA[i];
        mpA[arrA[i]] = 1;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arrB[i];
        mpB[arrB[i]] = 1;
    }
    int maxs = -1;
    vector<int> ans;
    // 두 배열에 공통 된 수 중에서 가장 큰 값 저장
    for (auto k : mpA) {
        if (mpB.count(k.first)) {
            if (maxs < k.first) {
                maxs = k.first;
            }
        }
    }
    int idxA = 0, idxB = 0;
    //  앞에 큰 값이 나오는게 사전 순으로 가장 나중이기에 큰 값부터 넣어줌
    // 넣을 때마다 구간을 갱신
    for(int i = maxs; i>=1;i--){
        while(true){
            bool check1 = false, check2 = false;
            int k1 = 0, k2 = 0;
            for(int j = idxA; j<n;j++){
                if(arrA[j] == i){
                    check1 = true;
                    k1 = j;
                    break;
                }
            }
            for(int j = idxB; j<m;j++){
                if(arrB[j] == i){
                    check2 = true;
                    k2 = j;
                    break;
                }
            }
            if(check1 && check2){
              idxA = k1 + 1;  
              idxB = k2 + 1;
              ans.push_back(i);
            } 
            else break;
        }
    }
    cout << ans.size() << "\n";
    for (int k : ans) cout << k << " ";
}