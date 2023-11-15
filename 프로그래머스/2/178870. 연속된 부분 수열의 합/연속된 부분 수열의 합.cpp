#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int s = 0, e = 1;
    if(sequence[0] == k){
        return {0, 0};
    }
    int len = sequence.size() + 1;
    int sum = sequence[s] + sequence[e];
    while(s <= e && e < sequence.size()){
        if(sum == k){
            if(len > e - s){
                answer[0] = s;
                answer[1] = e;
                len = e - s;
            }
            e++;
            sum += sequence[e];
            continue;
        }
        if(sum < k){
            e++;
            sum += sequence[e];
        } 
        else{
            sum -= sequence[s];
            s++;
        }
        
    }
    return answer;
}