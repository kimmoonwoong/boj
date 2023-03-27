import java.util.*;
import java.io.*;

public class Main{
    public static void main(String []args) throws NumberFormatException, IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Integer arr1[] = new Integer[n];
        Integer arr2[] = new Integer[n];
        Integer arr3[] = new Integer[n];

        for (int i = 0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            arr1[i] = a + b;
            arr2[i] = b + c;
            arr3[i] = a + c;
        }
        Arrays.sort(arr1, Collections.reverseOrder());
        Arrays.sort(arr2, Collections.reverseOrder());
        Arrays.sort(arr3, Collections.reverseOrder());
        Integer[] arr[] = { arr1, arr2, arr3};
        int max = 0;
        for (int i = 0;i<3;i++){
            int sum = 0;
            for (int j = 0;j<k;j++){
                sum += arr[i][j];
            }
            max = Math.max(max , sum);
        }
        System.out.println(max);
    }
}