#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end());
    int idx = 0;
    while(idx < targets.size()){
        int e = targets[idx][1];
        idx++;
        answer++;
        while(idx < targets.size() && e > targets[idx][0]){
            if(e > targets[idx][1]) e = targets[idx][1];
            idx++;
        }
    }
    
    return answer;
}