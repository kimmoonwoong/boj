import java.io.*;
import java.util.*;
public class Main {

    static int INF = -1;
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int dp[][] = new int[n + 1][m + 1];
        int arr[][] = new int[n + 1][n + 1];
        for (int i = 0;i<k;i++){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (a>=b) continue;
            arr[a][b] = Math.max(arr[a][b], c);
        }
        for (int array[] : dp){
            Arrays.fill(array, INF);
        }
        dp[1][1] = 0;
        for (int i = 1;i<n;i++){
            for (int j = 1;j<m;j++){
                if (dp[i][j] == INF) continue;
                for (int next = i + 1; next<=n;next++){
                    if (arr[i][next] == 0) continue;
                    dp[next][j + 1] = Math.max(dp[next][j + 1], dp[i][j] + arr[i][next]);
                }
            }
        }
        int ans = 0;
        for (int i = 1;i<=m;i++){
            if (dp[n][i] == INF) continue;
            ans = Math.max(dp[n][i], ans);
        }
        System.out.println(ans);
    }
}