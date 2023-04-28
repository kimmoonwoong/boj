import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int k = Integer.parseInt(br.readLine());
        for (int i = 1;i<=k;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            Integer arr[] = new Integer[n];
            for (int j = 0;j<n;j++){
                arr[j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr, Collections.reverseOrder());
            int gap = 0;
            for (int j = 0;j<n - 1;j++){
                gap = Math.max(gap, arr[j] - arr[j + 1]);
            }
            sb.append("Class ").append(i).append("\n");
            sb.append("Max " + arr[0] + ", " + "Min " + arr[n - 1] + ", " + "Largest gap " + gap).append("\n");
        }
        System.out.println(sb);
    }
}
