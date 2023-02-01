class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for(int i = 1;i<=n;i++){
            int sum = i;
            for(int j = i + 1;j<=n;j++){
                sum += j;
                if(sum == n) answer++;
                else if(sum > n) break;
            }
        }
        answer+=1;
        return answer;
    }
}