import java.io.*;
import java.util.*;
public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long arr[] = new long[n + 1];
        st = new StringTokenizer(br.readLine());
        long ans = 0;
        Map<Long, Long> map = new HashMap<>();
        for (int i = 1;i<=n;i++){
            int k  = Integer.parseInt(st.nextToken());
            arr[i] = arr[i - 1] + k;
            if (arr[i] == m) ans++;

            if (map.containsKey(arr[i] - m)){
                ans += map.get(arr[i] - m);
            }

            if (!map.containsKey(arr[i])){
                map.put(arr[i], (long)1);
            }
            else{
                map.replace(arr[i], map.get(arr[i]) + 1);
            }
        }
        System.out.println(ans);
    }
}