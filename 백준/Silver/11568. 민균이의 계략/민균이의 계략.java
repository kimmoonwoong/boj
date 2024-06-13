import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int dp[] = new int[1001];
        int array[] = new int[1001];
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0;i<n;i++){
            array[i] = Integer.parseInt(st.nextToken());
        }
        dp[0] = 1;
        int max = 0;
        for(int i = 1;i<=n;i++){
            int val = 0;
            for(int j = i -1; j>=0;j--){
                if(array[i] > array[j] && val < dp[j]){
                    val = dp[j];
                }
            }
            dp[i] = val + 1;
            max=  Math.max(dp[i] , max);
        }
        System.out.println(max);
    }
}