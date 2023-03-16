import java.io.*;
import java.util.*;
public class Main {
    static List<Integer> list[];
    static boolean visited[];
    static int dp[][];

    static void DFS(int start){
        visited[start] = true;
        dp[start][0] = 0;
        dp[start][1] = 1;

        for (int next: list[start]){
            if (visited[next]) continue;

            DFS(next);
            dp[start][0] += dp[next][1];
            dp[start][1] += Math.min(dp[next][1], dp[next][0]);
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        list = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        dp = new int[n + 1][2];

        for (int i = 1;i<=n;i++){
            list[i] = new ArrayList<>();
        }

        for (int i = 0;i<n - 1;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[a].add(b);
            list[b].add(a);
        }
        DFS(1);
        System.out.println(Math.min(dp[1][0], dp[1][1]));
    }
}