import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> map = new HashMap<>();

        for(int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            int k = Integer.parseInt(st.nextToken());

            if(map.containsKey(s)){
                map.replace(s,map.get(s) + k);
            }
            else{
                map.put(s,k);
            }
        }

        for (String s : map.keySet()){
            if(map.get(s) == 5){
                System.out.println("YES");
                System.exit(0);
            }
        }
        System.out.println("NO");
    }
}