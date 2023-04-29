import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n];
        int dp[] = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dp[0] = 1;
        int ans = 1;
        for (int i = 1;i<n;i++){
            int val = 0;

            for (int j = 0;j<i;j++){
                if (arr[j] < arr[i] && val < dp[j]) val = dp[j];
            }
            dp[i] = val + 1;
            ans = Math.max(dp[i], ans);
        }
        System.out.println(ans);

    }
}
