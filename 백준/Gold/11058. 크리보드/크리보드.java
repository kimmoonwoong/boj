    import java.io.*;
    import java.util.*;

    public class Main {
        public static void main(String[] args) throws NumberFormatException, IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            int n = Integer.parseInt(br.readLine());

            long dp[] = new long[101];

            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 3;
            dp[4] = 4;
            dp[5] = 5;
            dp[6] = 6;

            for (int i = 7;i<=n;i++){
                for (int j = 1;j<=i - 3;j++){
                    dp[i] = Math.max(dp[j] * (i - j - 1), dp[i]);
                }
            }
            System.out.println(dp[n]);
        }
    }