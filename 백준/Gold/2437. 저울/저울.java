import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        int sum = 1;
        for (int i =0;i<n;i++){
            if (sum >= arr[i]) sum+= arr[i];
            else break;
        }
        System.out.println(sum);
    }
}