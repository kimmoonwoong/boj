#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;  
    
    int deliidx = n - 1;
    int pickidx = n - 1;
    
    while(deliveries[deliidx] == 0) deliidx--;
    while(pickups[pickidx] == 0) pickidx--;
    
    while(deliidx >= 0 || pickidx >= 0){ 
        answer += max(deliidx + 1, pickidx + 1);
        int box = 0;
    
        while(deliidx >= 0){
            if(box + deliveries[deliidx] <= cap){
                box += deliveries[deliidx];
                deliidx--;
            } 
            else{
                deliveries[deliidx] -= (cap - box);
                break;
            }
        }
        box = 0;
        while(pickidx >= 0){
            if(box + pickups[pickidx] <= cap){
                box += pickups[pickidx];
                pickidx--;
            }
            else{
                pickups[pickidx] -= (cap - box);
                break;
            }
        }
    }
    
    return answer * 2;
}