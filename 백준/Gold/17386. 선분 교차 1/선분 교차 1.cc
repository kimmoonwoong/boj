#include <iostream>
#include <vector>
#define pii pair<long long, long long>
using namespace std;

int ccw(pii p1, pii p2, pii p3){
    long long tm = ((p2.first - p1.first) * (p3.second - p2.second)) - ((p2.second - p1.second) * (p3.first - p2.first));
    if(tm > 0) return 1;
    else if(tm == 0) return 0;
    else return -1;
}

int main() {
    vector<pii> arr(4);
    
    cin >> arr[0].first >> arr[0].second >> arr[1].first >> arr[1].second;
    cin >> arr[2].first >> arr[2].second >> arr[3].first >> arr[3].second;
    int check1 = ccw(arr[0], arr[1], arr[2]) * ccw(arr[0], arr[1], arr[3]);
    int check2 = ccw(arr[2], arr[3], arr[0]) * ccw(arr[2], arr[3], arr[1]);
    if(check1 == 0 && check2 == 0){
        if(arr[1] < arr[0]) swap(arr[1], arr[0]);
        if(arr[3] < arr[2]) swap(arr[2], arr[3]);
        
        if(arr[1] >= arr[2] && arr[0] <= arr[3]) cout << 1;    
    
        else cout << 0;
    }
    else{
        if(check1 <=0 && check2 <= 0) cout << 1;
        else cout << 0;
    }
    return 0;
}