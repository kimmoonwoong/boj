import java.io.*;
import java.util.*;


public class Main {
    static class XY{
        int x;
        int y;
        String ans;

        public XY(int x ,int y,String ans){
            this.x = x;
            this.y =y;
            this.ans = ans;
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s1 = br.readLine();
        String s2 = br.readLine();

        int dp[][] = new int[s1.length() + 1][s2.length() + 1];

        for (int i = 1;i<=s1.length();i++) {
            for (int j = 1; j <= s2.length(); j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        System.out.println(dp[s1.length()][s2.length()]);

        if (dp[s1.length()][s2.length()] != 0){
            int nx = s1.length(); int ny = s2.length();
            String ans = "";
            while (nx > 0 && ny > 0){

                if (dp[nx - 1][ny] == dp[nx][ny]){
                    nx--;
                }
                else if (dp[nx][ny - 1] == dp[nx][ny]) ny--;
                else{
                    ans += Character.toString(s1.charAt(nx - 1));
                    nx--;
                    ny--;
                }
            }
            StringBuilder sb = new StringBuilder(ans);
            System.out.println(sb.reverse().toString());

        }
    }
}