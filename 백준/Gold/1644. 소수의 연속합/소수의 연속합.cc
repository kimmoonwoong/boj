#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[4000000];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 2;i<=4000000;i++){
        arr[i] = i;
    }
    for(int i = 2;i<=sqrt(4000000);i++){
        if(arr[i] == 0) continue;

        for(int j = i * i; j<=4000000;j+=i){
            arr[j] = 0;
        }
    }
    int n; cin >> n;
    vector<int> vec;
    for(int i = 2;i<=n;i++){
        if(arr[i] != 0) {
            vec.push_back(arr[i]);
        }
    }
    int start = 0, end = 1;
    int sum = vec[start] + vec[end];
    int cnt = 0;
    while (end <= vec.size() || start >= end){
        if(sum < n){
            end++;
            sum += vec[end];
        }
        else if(sum >= n){
            if(sum == n) cnt++;
            sum -= vec[start];
            start++;
        }
    }
    cout << cnt;
    return 0;
}