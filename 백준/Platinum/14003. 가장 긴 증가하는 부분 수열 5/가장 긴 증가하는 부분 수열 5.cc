#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000002];
int totalarr[1000002];
int indexarr[1000002];
int main() {
    int n; cin >> n;
    int temp;
    int index = 0;
    for(int i = 0;i<n;i++){
        cin >> temp;
        totalarr[i] = temp;
        if(i == 0) {
            indexarr[i] = 0;
            arr[index++] = temp;
        }
        else{
            if(arr[index - 1] < temp) {
                indexarr[i] = index;
                arr[index++] = temp;
            }
            else{
                int k = lower_bound(arr, arr+index, temp) - arr;
                indexarr[i] = k;
                arr[k] = temp;
            }
        }
    }
    cout << index << endl;
    vector<int> vec;
    for(int i = n - 1;i>=0;i--){
        if(index == indexarr[i] + 1){
            vec.push_back(totalarr[i]);
            index--;
        }
    }
    int size = vec.size();
    for(int i = 0;i<size;i++){
        cout << vec.back() << " ";
        vec.pop_back();
    }
    return 0;
}