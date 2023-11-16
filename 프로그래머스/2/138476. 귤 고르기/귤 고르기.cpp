#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#define pii pair<int, int>
using namespace std;

bool cmp(pii o1, pii o2){
    return o1.first > o2.first;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> mp;
    
    for(int now : tangerine){
        mp[now]++;
    }
    
    vector<pii> arr;
    for(auto now : mp){
        arr.push_back({now.second, now.first});
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(pii now : arr){
        answer++;
        k -= now.first;
        if(k <= 0) break;
    }
    return answer;
}