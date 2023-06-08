import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
        if(n == 1){
            System.out.println("YES");
            System.out.println(arr[0] * 2);
            System.out.println(arr[0] - (arr[0] * 2));
            System.exit(0);
        }
        int k = arr[1] - arr[0];
        for(int i = 2;i<n;i++){
            if(arr[i] - arr[i - 1] != k) {
                System.out.println("NO");
                System.exit(0);
            }
        }

        System.out.println("YES");
        for(int i = 0;i<n;i++) System.out.print(arr[i] * 2 + " ");
        System.out.println();
        for(int i = 0;i<n;i++) System.out.print(arr[i] - (arr[i] * 2) + " ");
    }
}