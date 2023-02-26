import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Map<Integer, Integer> map = new HashMap<>();
        Queue<Integer> queue = new LinkedList<>();
        st = new StringTokenizer(br.readLine());
        int max = 1;
        for (int i = 0;i<n;i++){
            int k = Integer.parseInt(st.nextToken());
            queue.add(k);
            if (map.containsKey(k)){
                map.replace(k, map.get(k) + 1);
                max = Math.max(max, map.get(k));
            }
            else map.put(k, 1);

            if (queue.size() == m){
                double l = Math.ceil((double) (m * 9) / 10);
                if (max >= l){
                    System.out.println("YES");
                    System.exit(0);
                }

                int pop = queue.poll();
                map.replace(pop, map.get(pop) - 1);
            }
        }
        System.out.println("NO");

    }
}