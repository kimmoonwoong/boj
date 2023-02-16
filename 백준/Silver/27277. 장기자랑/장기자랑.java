import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int arr[] = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int ans = 0;
        Arrays.sort(arr);
        ans += arr[n - 1];
        int end = n - 2;
        int start = 0;
        int tempend = end;
        int tempstart = start;
        int i = 0;
        while (true){
            if (i % 2 == 0){
                ans += Math.max(0,arr[start] - arr[end + 1]);
                tempstart = start;
                start++;
            }
            else{
                ans += Math.max(0,arr[end] - arr[start - 1]);
                tempend = end;
                end--;
            }
            i++;
            if (tempend - tempstart <= 0) break;

        }
        System.out.println(ans);
    }
}