import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        while (T-->0){
            int n = Integer.parseInt(br.readLine());

            StringTokenizer st = new StringTokenizer(br.readLine());

            PriorityQueue<Long> queue = new PriorityQueue<>();

            for(int i = 0;i<n;i++){
                queue.add(Long.parseLong(st.nextToken()));
            }
            if(n == 1) {
                sb.append(1).append("\n");
                continue;
            }
            long cnt = 1;

            while (queue.size() > 1){
                long c1 = queue.poll();
                long c2 = queue.poll();
                cnt = cnt * ((c1 * c2) % 1000000007) % 1000000007;
                queue.add(c1 * c2);
            }
            sb.append(cnt).append("\n");
        }
        System.out.println(sb);
    }
}