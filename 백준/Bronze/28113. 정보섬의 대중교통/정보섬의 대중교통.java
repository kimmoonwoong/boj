import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int k = b - n + n;
        if(a == k) System.out.println("Anything");
        else if(a < k) System.out.println("Bus");
        else System.out.println("Subway");
    }
}