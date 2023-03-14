import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if (s.charAt(0) == '0'){
            System.out.println(0);
            System.exit(0);
        }

        int dp[] = new int[s.length() + 1];
        dp[0] = 1;
        for (int i = 1;i<=s.length();i++){
                if (i == 1){
                    dp[i] = dp[i - 1] % 1000000;
                    continue;
                }
                if (s.charAt(i - 1) != '0'){
                    dp[i] = dp[i - 1] % 1000000;
                }
                if (s.charAt(i - 2) == '0') continue;
                int plus = Integer.parseInt(s.substring(i - 2, i - 1) + s.substring(i- 1, i));
                if (plus >= 10 && plus <= 26){
                    dp[i] += dp[i - 2] % 1000000;
                }
        }
        System.out.println(dp[s.length()] % 1000000);
    }

}
