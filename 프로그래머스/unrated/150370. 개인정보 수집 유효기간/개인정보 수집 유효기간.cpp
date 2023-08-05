#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;

int term[100];

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> mp;
    vector<string> s = split(today, '.');
    int todayarr[3] = {stoi(s[0]), stoi(s[1]), stoi(s[2])};
    
    for(string se : terms){
        vector<string> tem = split(se, ' ');
        mp[tem[0]] = stoi(tem[1]);
    }
    int idx = 1;
    for(string se : privacies){
        vector<string> pri = split(se, ' ');
        vector<string> olday = split(pri[0], '.');
        olday[1] = to_string(stoi(olday[1]) + mp[pri[1]]);
        int k = stoi(olday[1]);
        while(k > 12){
            olday[0] = to_string(stoi(olday[0]) + 1);
            k -= 12;
        }
        olday[1] = to_string(k);
        if(stoi(olday[2]) - 1 <= 0){
            olday[2] = "28";
            olday[1] = to_string(stoi(olday[1]) - 1);
        }
        else{
            olday[2] = to_string(stoi(olday[2]) - 1);
        }
        int oldayarr[3] = {stoi(olday[0]), stoi(olday[1]), stoi(olday[2])};
        if(oldayarr[0] < todayarr[0]){
            answer.push_back(idx);
            idx++;
            continue;
        }
        else if(oldayarr[0] == todayarr[0] && oldayarr[1] < todayarr[1]){
            answer.push_back(idx);
            idx++;
            continue;
        } 
        else if(oldayarr[0] == todayarr[0] && oldayarr[1] == todayarr[1] && oldayarr[2] < todayarr[2]){
            answer.push_back(idx);
            idx++;
            continue;
        }
        
        idx++;
    }
    return answer;
}