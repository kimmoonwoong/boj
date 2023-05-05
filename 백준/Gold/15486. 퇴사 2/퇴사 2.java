import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[][] = new int[n + 2][2];
        for (int i = 1;i< n + 1;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            arr[i][0] = t;
            arr[i][1] = p;
        }

        int dp[] = new int[n + 2];
        int ans = 0;
        int max = 0;
        for (int i = 1;i<n + 1;i++){
            max = Math.max(max, dp[i]);
            int next = i + arr[i][0];
            if (next < n + 2){
                dp[next] = Math.max(dp[next], max + arr[i][1]);
                ans = Math.max(dp[next], ans);
            }
        }
        System.out.println(ans);
    }
}