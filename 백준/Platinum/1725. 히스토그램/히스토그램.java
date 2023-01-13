import java.io.*;
import java.util.*;
;
public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int array[] = new int[n + 2];
        Stack<Integer> stack = new Stack<>();
        int max = 0;
        for(int i = 1;i<=n;i++){
            array[i] = Integer.parseInt(br.readLine());
        }
        stack.add(0);
        for (int i = 1;i<=n+1;i++){
            while (!stack.isEmpty()){
                int peek = stack.peek();
                if(array[peek] <= array[i]) break;
                stack.pop();
                max = Math.max(max, array[peek] * (i - stack.peek() - 1));
            }
            stack.add(i);
        }
        System.out.println(max);

    }
}