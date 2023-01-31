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

            int dp_1[] = new int[n];
            int dp_2[] = new int[n];
            dp_1[0] = 1;
            dp_2[0] = 1;

            for(int i = 1;i<n;i++){
                dp_1[i] = 1;
                int val = 0;
                for (int j = 0;j<i;j++){
                    if (arr[j] < arr[i] && dp_1[j]> val) val = dp_1[j];
                }
                dp_1[i] = val + 1;
            }
            for (int i = n - 1;i>=0;i--){
                int val = 0;
                for (int j = n - 1; j>i;j--){
                    if (arr[j] < arr[i] && dp_2[j] > val) val = dp_2[j];
                }
                dp_2[i] = val + 1;
            }
            int ans = 0;
            for (int i = 0;i<n;i++){
                ans = Math.max((dp_1[i] + dp_2[i]), ans);
            }
            System.out.println(ans - 1);
        }
    }