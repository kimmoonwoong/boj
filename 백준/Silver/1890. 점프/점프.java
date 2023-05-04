import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long dp[][] = new long[n][n];
        int map[][] = new int[n][n];
        dp[0][0] = 1;
        for (int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0;j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 0) continue;
                if (j + map[i][j] < n) dp[i][j + map[i][j]] += dp[i][j];
                if (i + map[i][j] < n) dp[i + map[i][j]][j] += dp[i][j];
            }
        }
        System.out.println(dp[n - 1][n - 1]);
    }
}