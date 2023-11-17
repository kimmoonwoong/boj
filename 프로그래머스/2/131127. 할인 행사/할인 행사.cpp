#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> need;
    for(int i = 0;i<want.size();i++) need[want[i]] = number[i];
    for(int i = 0;i<=discount.size() - 10;i++){
        map<string, int> mp;
        for(int j = i;j<i + 10;j++){
            mp[discount[j]]++;
        }
        bool check = false;
        for(auto now : need){
            if(mp.find(now.first) == mp.end()){
                check = true;
                break;
            }
            if(mp[now.first] != now.second){
                check = true;
                break;
            }
        }
        if(!check) answer++;
    }
    return answer;
}