import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int ans = 0;

        Map<Character, Integer> map = new HashMap<>();

        String s = br.readLine();
        int arr[] = new int[10];
        for (int i = 0;i<s.length();i++){
            int k = Integer.parseInt(s.substring(i,i + 1));
            arr[k]++;
        }
        int k = arr[6] + arr[9];
        if (k % 2==0){
            arr[6] = k / 2;
            arr[9] = k / 2;
        }
        else{
            arr[6] = k / 2 + 1;
            arr[9] = k / 2 + 1;
        }
        for (int i = 0;i<=9;i++){
            ans = Math.max(ans, arr[i]);
        }
        System.out.println(ans);
    }
}