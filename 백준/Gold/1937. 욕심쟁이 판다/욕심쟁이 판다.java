import java.io.*;
import java.util.*;


public class Main {
    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};

    static int map[][];
    static int n;
    static int dp[][];
    static int ans = 0;
    static int DFS(int x, int y){
        if (dp[x][y] != 0) return dp[x][y];

        dp[x][y] = 1;

        for (int i = 0;i<4;i++){
            int nextx = x + next_x[i];
            int nexty = y + next_y[i];

            if (nextx < 0 || nexty<0|| nextx>=n || nexty>=n) continue;
            if (map[nextx][nexty] > map[x][y]){
                dp[x][y] = Math.max(dp[x][y], DFS(nextx,nexty) + 1);
            }
        }

        return dp[x][y];
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        dp = new int[n][n];
        for (int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0;j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i<n;i++){
            for (int j = 0;j<n;j++){
                ans = Math.max(ans,DFS(i,j));
            }
        }
        System.out.println(ans);
    }
}