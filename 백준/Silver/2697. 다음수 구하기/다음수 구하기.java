import java.util.*;
import java.io.*;

public class Main {

    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        while (T-->0){
            String s = br.readLine();
            int index = -1;
            int arr[] = new int[10];
            for (int i = s.length();i >=2;i--){
                if (Integer.parseInt(s.substring(i - 1 , i)) > Integer.parseInt(s.substring(i - 2, i - 1))){
                    index = i - 2;
                    break;
                }
            }
            if (index == -1 || s.length() == 1){
                sb.append("BIGGEST").append("\n");
                continue;
            }

            String ans = "";
            for (int i = 0;i<index;i++){
                ans += s.substring(i, i + 1);
            }

            for (int i = index;i<s.length();i++){
                int k = Integer.parseInt(s.substring(i, i + 1));
                arr[k]++;
            }
            for (int i = Integer.parseInt(s.substring(index, index + 1)) + 1;i<10;i++){
                if (arr[i] > 0){
                    ans += Integer.toString(i);
                    arr[i]--;
                    break;
                }
            }
            for (int i = 0;i<10;i++){
                if (arr[i] > 0){
                    while (arr[i]-- >0){
                        ans += Integer.toString(i);
                    }
                }
            }
            sb.append(ans).append("\n");
        }
        System.out.println(sb);
    }
}