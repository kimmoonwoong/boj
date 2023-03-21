import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Integer arr[] = new Integer[n];
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0;i<n;i++){
            queue.add(Integer.parseInt(br.readLine()));
        }
        int ans = 0;
        for (int i = 1;i<=n;i++){
            int k = queue.poll();
            ans = Math.max(ans, k * i);
        }
        System.out.println(ans);
    }
}