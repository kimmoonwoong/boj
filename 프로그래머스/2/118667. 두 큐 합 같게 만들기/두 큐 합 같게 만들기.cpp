#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;
    for(int now : queue1) {
        sum1 += (long long)now;
        q1.push(now);
    }
    for(int now : queue2){
        sum2 += (long long)now;
        q2.push(now);
    } 
    
    while(true){
        if(answer >= 600002){
            answer = -1;
            break;
        }
        if(sum1 == sum2) break;
        if(sum1 > sum2){
            sum1 -= (long long)q1.front();
            sum2 += (long long)q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else{
            sum2 -= (long long)q2.front();
            sum1 += (long long)q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        answer++;
    }
    
    return answer;
}