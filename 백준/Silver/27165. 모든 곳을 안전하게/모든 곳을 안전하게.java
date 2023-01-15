import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n + 1];
        int k = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Integer> list = new ArrayList<>();
        for (int i = 0;i<n + 1;i++){
            arr[i] = Integer.parseInt(st.nextToken());
            if(arr[i] == 1) {
                k++;
                list.add(i);
            }
        }
        int x = Integer.parseInt(br.readLine());

        if(k >= 3){         // 문제 없음
            System.out.println("NO");
        }
        else if (k == 2){           // 문제 없음
            int a = list.get(0);
            int b = list.get(1);

            if(b - a == x){
                System.out.println("YES");
                System.out.print(a + " " + b);
            }
            else{
                System.out.println("NO");
            }
        }
        else if(k == 1){            
            if(list.get(0) + x <= n && arr[list.get(0) + x] >= 2){
                System.out.println("YES");
                System.out.print(list.get(0) + " " + (list.get(0) + x));
            }
            else if(list.get(0) - x >=0 && arr[list.get(0) - x] >= 3){
                System.out.println("YES");
                System.out.println((list.get(0) - x) + " " + list.get(0));
            }
            else System.out.println("NO");
        }
        else{
            for (int i = 0;i<=n-x;i++){
                if (arr[i] >= 3 && arr[i + x] >= 2){
                    System.out.println("YES");
                    System.out.print(i + " " + (i + x));
                    System.exit(0);
                    break;
                }
            }
            System.out.println("NO");
        }
    }
}