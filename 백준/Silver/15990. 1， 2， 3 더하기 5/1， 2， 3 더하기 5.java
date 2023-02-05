import java.io.*;
import java.util.*;

public class Main {
    static int INF = 1000000009;
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long dp[][] = new long[100001][3];
        dp[1][0] = 1;
        dp[2][1] = 1;
        dp[3][0] = 1;
        dp[3][1] = 1;
        dp[3][2] = 1;
        for(int i = 4;i<=100000;i++){
            dp[i][0] = (dp[i-1][1] + dp[i - 1][2]) % INF;
            dp[i][1] = (dp[i-2][0] + dp[i-2][2]) % INF;
            dp[i][2] = (dp[i-3][0] + dp[i-3][1]) % INF;
        }
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            int n = Integer.parseInt(br.readLine());
            long result = (dp[n][0] + dp[n][1] + dp[n][2]) % 1000000009;
            sb.append(result).append("\n");
        }
        System.out.println(sb);
    }
}