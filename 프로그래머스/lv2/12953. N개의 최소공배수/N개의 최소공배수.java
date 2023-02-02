class Solution {
    
    static int gcd(int a, int b){
        if(b == 0) return a;
        else return gcd(b,a%b);
    }
    public int solution(int[] arr) {
        int answer = 0;
        
        if(arr.length == 1) return arr[0];
        else{
            int g = (arr[0] * arr[1]) / gcd(arr[0],arr[1]);
            for(int i = 2;i<arr.length;i++){
                g = (g * arr[i]) / gcd(g,arr[i]);
            }
            answer = g;
        }
        return answer;
    }
}