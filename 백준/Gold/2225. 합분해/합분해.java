import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int arr[][] = new int[k + 1][n + 1];
        int dp[][] = new int[k + 1][n + 1];
        dp[0][0] =1;
        arr[0][0] = 1;
        for (int i = 1;i<=n;i++){
            dp[1][i] = 1;
            arr[1][i] = arr[1][i - 1] + 1;
        }
        for (int i = 1;i<=k;i++) {
            dp[i][1] = i;
            arr[i][1] = i;
        }

        for (int i = 2;i<=k;i++){
            for (int j = 2;j<=n;j++){
                dp[i][j] = arr[i - 1][j] + 1 % 1000000000;
                arr[i][j] = (arr[i][j - 1] + dp[i][j]) % 1000000000;
            }
        }
        System.out.println(dp[k][n] % 1000000000);
    }
}