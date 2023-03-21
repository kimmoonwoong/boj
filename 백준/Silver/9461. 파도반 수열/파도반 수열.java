    import java.io.*;
    import java.util.*;

    public class Main {

        public static void main(String[] args) throws NumberFormatException, IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int T  = Integer.parseInt(br.readLine());
            StringBuilder sb = new StringBuilder();
            while (T-->0){
                int n = Integer.parseInt(br.readLine());
                long dp[] = new long[101];
                dp[0] = 1;
                dp[1] = 1;
                dp[2] = 1;
                for(int i = 3;i<=n;i++){
                    dp[i] = dp[i - 2] + dp[i-3];
                }
                sb.append(dp[n - 1]).append("\n");
             }
            System.out.println(sb);
        }
    }