import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0;i<n;i++) map.put(br.readLine(), i);
        int arr[] = new int[n];
        for (int i = 0;i<n;i++) arr[i] = map.get(br.readLine());
        int ans = 0;
        for (int i = 0;i<n - 1;i++){
            for (int j = i + 1;j<n;j++){
                if (arr[i] > arr[j]) {
                    ans++;
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}