import java.io.*;
import java.util.*;
;
public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if(n== 0) break;
            long array[] = new long[n + 2];
            Stack<Integer> stack = new Stack<>();
            long max = 0;
            for (int i = 1; i <= n; i++) {
                array[i] = Integer.parseInt(st.nextToken());
            }
            stack.add(0);
            for (int i = 1; i <= n + 1; i++) {
                while (!stack.isEmpty()) {
                    int peek = stack.peek();
                    if (array[peek] <= array[i]) break;
                    stack.pop();
                    max = Math.max(max, array[peek] * (i - stack.peek() - 1));
                }
                stack.add(i);
            }
            sb.append(max).append("\n");
        }
        System.out.println(sb);

    }
}