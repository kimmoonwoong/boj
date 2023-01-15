import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int num = Integer.parseInt(st.nextToken());
        int current = num;
        int result = 0;
        for(int i = 1;i<n;i++){
            int k = Integer.parseInt(st.nextToken());
            if(current + 1 == k) {
                current = k;
            }
            else{
                result+=num;
                num = k;
                current = k;
            }
        }
        result += num;
        System.out.println(result);
    }
}