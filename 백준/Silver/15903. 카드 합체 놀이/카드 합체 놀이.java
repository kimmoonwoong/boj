    import java.io.*;
    import java.util.*;

    public class Main {
        public static void main(String[] args) throws NumberFormatException, IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            PriorityQueue<Long> queue = new PriorityQueue<>();
            st = new StringTokenizer(br.readLine());
            for (int i = 0;i<n;i++){
                long k = Long.parseLong(st.nextToken());
                queue.add(k);
            }

            for (int i = 0;i<m;i++){
                long sum = queue.poll() + queue.poll();
                queue.add(sum);
                queue.add(sum);
            }
            long ans = 0;
            while (!queue.isEmpty()){
                ans += queue.poll();
            }
            System.out.println(ans);
        }
    }