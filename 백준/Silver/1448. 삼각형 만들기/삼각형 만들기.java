    import java.io.*;
    import java.util.*;

    public class Main {
        public static void main(String[] args) throws NumberFormatException, IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            int n = Integer.parseInt(br.readLine());

            Integer arr[] = new Integer[n];
            for (int i = 0;i<n;i++){
                arr[i] = Integer.parseInt(br.readLine());
            }
            Arrays.sort(arr, Collections.reverseOrder());
            int ans = -1;
            for (int i = 0;i<n - 2;i++){
                if (arr[i + 1] + arr[i + 2] > arr[i]){
                    ans = (arr[i] + arr[i + 1] + arr[i + 2]);
                    break;
                }
            }
            System.out.println(ans);
        }
    }