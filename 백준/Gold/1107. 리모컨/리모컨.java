import java.io.*;
import java.util.*;


public class Main {
    static boolean notbutton[];

    static int isCheck(int i){
        if (i == 0) return !notbutton[0] ? 1:-1;
        int k = 0;
        while (i != 0){
            if (notbutton[i % 10]) return -1;
            i/=10;
            k++;
        }
        return k;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        notbutton = new boolean[10];
        if (m > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0;i<m;i++) {
                int k = Integer.parseInt(st.nextToken());

                notbutton[k] = true;
            }
        }
        if (n == 100){
            System.out.println(0);
            System.exit(0);
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0;i<=1000000;i++){
            int check = isCheck(i);
            int temp = Integer.MAX_VALUE;
            if (check != -1){
                temp = Math.min(check + Math.abs(i - n), temp);
            }

            temp = Math.min(temp, Math.abs(100 - i) + Math.abs(i - n));

            ans = Math.min(temp, ans);
        }
        System.out.println(ans);


    }
}