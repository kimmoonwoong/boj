import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a= Integer.parseInt(st.nextToken());
        int b= Integer.parseInt(st.nextToken());

        int c = Integer.parseInt(br.readLine());

        if (a + b >= c * 2){
            System.out.println((a + b) - (c * 2));
        }
        else {
            System.out.println(a+b);
        }

    }
}