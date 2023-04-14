import java.util.*;
import java.io.*;

public class Main {

    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int max = 0;
        int ii = 1;
        int jj = 1;
        for (int i = 1;i<=9;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1;j<=9;j++){
                int k = Integer.parseInt(st.nextToken());
                if (max < k){
                    max = k;
                    ii = i;
                    jj = j;
                }
            }
        }
        System.out.println(max);
        System.out.println(ii + " " + jj);
    }
}
