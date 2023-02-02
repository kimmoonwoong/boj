#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int round = 0;
    
    while(true){
        if(a == b){
            break;
        }
        
        if(a%2 == 1){
            a = a/2+1;
        }
        else{
            a = a/2;
        }
        
        if(b%2 == 1){
            b = b/2+1;
        }
        else{
            b = b/2;
        }
        round++;
    }

    return round;
}