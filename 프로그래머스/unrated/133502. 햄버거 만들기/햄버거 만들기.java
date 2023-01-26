import java.util.*;

class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        
        List<Integer> list = new ArrayList<>();
        
        for(int next: ingredient){
            list.add(next);
            
            if(list.size() >=4){
                if(list.get(list.size() - 4) == 1 && list.get(list.size() - 3) == 2 &&
                  list.get(list.size() - 2) == 3 && list.get(list.size() - 1) == 1){
                    answer++;
                    for(int i = 4;i>0;i--){
                        list.remove(list.size() - i);
                    }
                }
            }
        }
        return answer;
    }
}