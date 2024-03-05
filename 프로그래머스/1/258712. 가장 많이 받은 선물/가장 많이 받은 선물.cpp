#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, int> mp;
    map<int, int> cnt;
    vector<vector<int>> arr(friends.size(), vector<int>(friends.size()));
    
    for(int i = 0;i<friends.size();i++) mp[friends[i]] = i;
    
    for(string s : gifts){
        int idx = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == ' '){
                idx = i;
                break;
            }
        }
        
        string send = s.substr(0, idx);
        string recv = s.substr(idx + 1, s.length());
        arr[mp[send]][mp[recv]]++;
        cnt[mp[send]]++;
        cnt[mp[recv]]--;
    }
    
    for(int i = 0;i<friends.size();i++){
        int k = 0;
        for(int j = 0;j<friends.size();j++){
            if(i == j) continue;
            
            if(arr[i][j] > arr[j][i]) k++;
            else if((arr[i][j] == 0 && arr[j][i] == 0) || arr[i][j] == arr[j][i]){
                if(cnt[i] > cnt[j]) k++;
            }
        }
        answer = max(answer, k);
    }
    return answer;
}