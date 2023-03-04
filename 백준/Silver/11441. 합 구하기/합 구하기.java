import java.io.*;
import java.util.*;
public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1;i<=n;i++){
            arr[i] = Integer.parseInt(st.nextToken()) + arr[i - 1];
        }

        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b=  Integer.parseInt(st.nextToken());
            sb.append(arr[b] - arr[a - 1]).append("\n");
        }
        System.out.println(sb);
    }
}