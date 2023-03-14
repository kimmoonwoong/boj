import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int count[] = new int[27];
        for (int i = 0;i<n;i++){
            String s = br.readLine();
            int size = (int)Math.pow(10, s.length() - 1);
            for (int j = 0;j<s.length();j++){
                count[s.charAt(j) - 'A'] += size;
                size/=10;
            }
        }
        Arrays.sort(count);
        int ans = 0;
        int num = 9;
        for (int i = 26;i>=0;i--){
            ans+= count[i] * num;
            num--;
        }
        System.out.println(ans);
    }
}
