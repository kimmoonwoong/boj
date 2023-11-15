#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
int INF = 1e9;
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<pii>> list(N + 1);
    vector<int> w(N + 1, INF);
    
    for(vector<int> now : road){
        list[now[0]].push_back({now[1], now[2]});
        list[now[1]].push_back({now[0], now[2]});
    }
    
    priority_queue<pii> pq;
    pq.push({1, 0});
    w[1] = 0;
    while(!pq.empty()){
        pii now = pq.top();
        pq.pop();
        
        if(w[now.first] < now.second) continue;
        
        for(pii next : list[now.first]){
            if(w[next.first] > w[now.first] + next.second){
                w[next.first] = w[now.first] + next.second;
                pq.push({next.first, w[next.first]});
            }
        }
    }
    
    for(int i = 1;i<=N;i++){
        if(w[i] <= K) answer++;
    }
    return answer;
}