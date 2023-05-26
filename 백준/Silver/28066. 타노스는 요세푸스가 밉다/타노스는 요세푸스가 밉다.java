import java.util.*;
import java.io.*;
public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Queue<Integer> queue = new LinkedList<>();

        for(int i = 1;i<=n;i++) queue.add(i);

        while (!queue.isEmpty()){
            if (queue.size() < k){
                System.out.println(queue.peek());
                break;
            }
            else{
                int f = queue.poll();
                for(int i = 0;i<k - 1;i++) queue.poll();
                queue.add(f);
            }
        }

    }
}