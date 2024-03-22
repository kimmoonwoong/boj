#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define pii pair<int ,int>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int idx = 0;
    queue<pii> q; 
    for(vector<int> now : attacks){
        idx = max(idx, now[0]);
        q.push({now[0] , now[1]});
    }
    int cnt = 0;
    for(int i = 0;i<=idx;i++){
        if(q.front().first == i){
            answer -= q.front().second;
            if(answer <= 0) break;
            q.pop();
            cnt = 0;
            continue;
        }
        
        if(answer < health){
            if(answer + bandage[1] >= health) answer = health;
            else answer += bandage[1];
        }
        cnt++;
        if(cnt == bandage[0]){
            cnt = 0;
            if(answer >= health) continue;
            if(answer + bandage[2] > health) answer = health;
            else answer += bandage[2];
        }
    }
    if(answer <= 0) answer = -1;
    return answer;
}