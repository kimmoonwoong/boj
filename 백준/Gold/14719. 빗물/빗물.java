import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int arr[] = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0;i<m;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int ans = 0;
        for (int i = 1;i<m;i++){

            int maxleft = 0;
            int maxright = 0;

            for (int j = 0;j<i;j++){
                maxleft = Math.max(maxleft, arr[j]);
            }
            for (int j = i + 1; j<m;j++){
                maxright = Math.max(maxright, arr[j]);
            }

            if (maxleft > arr[i] && maxright > arr[i]) {
                ans += Math.min(maxleft, maxright) - arr[i];
            }
        }
        System.out.println(ans);

    }
}