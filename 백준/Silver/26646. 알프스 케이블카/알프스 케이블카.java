import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n];
        int result = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0;i<n-1;i++){
            int a = Math.abs(arr[i] - arr[i + 1]);
            int b = arr[i] + arr[i + 1];

            result+= Math.pow(a,2) + Math.pow(b,2);
        }
        System.out.println(result);
    }
}