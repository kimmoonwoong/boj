import java.io.*;
import java.util.*;

public class Main {
    static class Title{
        int value;
        int index;

        public Title(int value, int index){
            this.value = value;
            this.index = index;
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Stack<Title> stack = new Stack<>();
        stack.add(new Title(0,-1));
        int result[] = new int[n];
        boolean isCheck = false;
        for(int i = 0;i<n;i++){
            int num = Integer.parseInt(br.readLine());
            if(i == 0 && num!=1){
                System.out.println(-1);
                System.exit(0);
            }
            if(stack.peek().value  + 1 < num){
                System.out.println(-1);
                System.exit(0);
            }
            if(i == 0){
                stack.add(new Title(num, i));
                continue;
            }

            if(stack.peek().value < num){
                stack.add(new Title(num, i - 1));
            }
            else if(stack.peek().value == num){
                stack.add(new Title(num, stack.peek().index));
            }
            else{
                int index = 0;
                while (stack.peek().value >= num){
                    Title pop = stack.pop();
                    if(pop.index != -1 && pop.value != 1){
                        result[pop.index]++;
                    }
                    index = pop.index;
                }
                if(stack.isEmpty()){
                    stack.add(new Title(num,i));
                }
                else{
                    stack.add(new Title(num, index));
                }
            }
        }
        while (!stack.isEmpty()){
            if(stack.peek().index == -1 || stack.peek().value == 0 || stack.peek().value == 1){
                stack.pop();
            }
            else{
                result[stack.pop().index]++;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i<n;i++){
            sb.append(result[i]).append("\n");
        }
        System.out.println(sb);
    }
}