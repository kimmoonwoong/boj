#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    int node;
    int cnt1 = 0;
    int cnt2 = 0;
    int nodecnt = 0;
    int size = 0;
    
    for(vector<int> arr : edges){
        size = max({size, arr[0], arr[1]});
    }
    
    vector<int> pushlist(size + 1);
    vector<int> pulllist(size + 1);
    
    for(vector<int> arr : edges){
        pushlist[arr[0]]++;
        pulllist[arr[1]]++;
    }
    
    for(int i = 1;i<=size;i++){
        if(pushlist[i] >= 2 && pulllist[i] == 0){
            node = i;
        }
    }

    for(vector<int> arr : edges){
        if(arr[0] == node) pulllist[arr[1]]--;
    }
    
    for(int i = 1;i<=size;i++){
        if(i == node) continue;
        if(pushlist[i] == 0) cnt1++;
        else if(pushlist[i] == 2 && pulllist[i] == 2) cnt2++;
    }
    answer.push_back(node);
    answer.push_back(pushlist[node] - cnt1 - cnt2);
    answer.push_back(cnt1);
    answer.push_back(cnt2);
    return answer;
}